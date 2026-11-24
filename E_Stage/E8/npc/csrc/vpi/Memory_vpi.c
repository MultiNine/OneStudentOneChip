#include <vpi_user.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PMEM_BASE 0x80000000u
#define PMEM_SIZE (128 * 1024 * 1024)

#define UART_BASE 0x10000000u
#define UART_END  0x10001000u

static uint8_t uart_lcr = 0;
static uint8_t uart_dll = 0;
static uint8_t uart_dlm = 0;

uint32_t pmem[PMEM_SIZE / 4] = {0};
uint32_t pmem_bval[PMEM_SIZE / 4] = {0};

extern unsigned long long get_time(void);

static uint32_t pmem_read(uint32_t raddr, uint32_t *rdata_bval) {
    *rdata_bval = 0;
    if (raddr == 0x10000005) {             // 读出UART状态
        return 0x00002000;                 // 发送就绪状态LSR[5]=1
    } else if (raddr == 0x20000000) {      // 读出时钟的低32位
        return get_time() & 0xffffffff;
    } else if (raddr == 0x20000004) {      // 读出时钟的高32位
        return get_time() >> 32;
    }

    uint32_t raddr_offset = raddr - PMEM_BASE;
    if (raddr_offset >= PMEM_SIZE) {
        return 0x00000000;
    }

    uint32_t index = (raddr_offset & ~0x3u) >> 2;
    *rdata_bval = pmem_bval[index];
    return pmem[index];
}

static void pmem_write(uint32_t waddr, uint32_t wdata, uint32_t wdata_bval, uint8_t wmask) {
    uint32_t addr = waddr;
    if (addr >= UART_BASE && addr < UART_END) {
        uint32_t offset = addr - UART_BASE;
        uint32_t lane = addr & 0x3;       // 取访问地址低2位
        // UART只允许发送确定的数据
        if ((wdata_bval >> (lane * 8)) & 0xffu) {
            vpi_printf("ERROR: UART write data contains X/Z!\n");
            vpi_control(vpiFinish, 1);
            return;
        }
        uint8_t data = (wdata >> (lane * 8)) & 0xff; // 从32位写数据中提取实际写入的8位数据
        // 操作UART寄存器
        if (offset == 0x3) {              // access LCR
            uart_lcr = data;
        } else if (offset == 0x1) {       // access DLM
            if (uart_lcr & 0x80) {
                uart_dlm = data;
            }
        } else if (offset == 0x0) {       // access DLL or THR
            if (uart_lcr & 0x80) {
                uart_dll = data;
            } else {
                fputc(data, stderr);
            }
        }
        return;
    }

    uint32_t waddr_offset = waddr - PMEM_BASE;
    uint32_t index = (waddr_offset & ~0x3u) >> 2;
    uint32_t old_data = pmem[index];
    uint32_t old_bval = pmem_bval[index];
    uint32_t byte_mask = 0u;

    for (int i = 0; i < 4; i++) {
        if (wmask & (0x1u << i)) {
            byte_mask |= (0xffu << (i * 8));
        }
    }

    pmem[index] = (old_data & ~byte_mask) | (wdata & byte_mask);
    pmem_bval[index] = (old_bval & ~byte_mask) | (wdata_bval & byte_mask);
}

// 访存C函数
/*=======================================================================*/
// vpi实现$pmem_read(addr, rdata)

static int pmem_read_compiletf(char*user_data)
{
    (void)user_data; // Avoid a warning since user_data is not used.
    return 0;
}

static int pmem_read_calltf(char*user_data)
{
    (void)user_data; // Avoid a warning since user_data is not used.

	vpiHandle callh = vpi_handle(vpiSysTfCall, NULL);
	vpiHandle argv  = vpi_iterate(vpiArgument, callh);

	vpiHandle addr_arg = vpi_scan(argv);
    vpiHandle rdata_arg = vpi_scan(argv);

	s_vpi_value addr_val;
	addr_val.format = vpiVectorVal;
	vpi_get_value(addr_arg, &addr_val); // get data from Verilog.
    if (addr_val.value.vector[0].bval != 0) {   // get X or Z status.
        vpi_printf("ERROR: Memory address contains X/Z!\n");
        vpi_control(vpiFinish, 1);
        return 0;
    }   

    uint32_t rdata_bval;
    uint32_t rdata = (uint32_t)pmem_read((uint32_t)addr_val.value.vector[0].aval, &rdata_bval);

    s_vpi_vecval vec = {(uint32_t)rdata, (uint32_t)rdata_bval};
    s_vpi_value rdata_val;
    rdata_val.format = vpiVectorVal;
    rdata_val.value.vector = &vec;
    vpi_put_value(rdata_arg, &rdata_val, NULL, vpiNoDelay); // write data back to Verilog.

    return 0;
}

void pmem_read_register(void)
{
    s_vpi_systf_data tf_data;

    tf_data.type      = vpiSysTask;
    tf_data.tfname    = "$pmem_read";
    tf_data.calltf    = pmem_read_calltf;
    tf_data.compiletf = pmem_read_compiletf;
    tf_data.sizetf    = 0;
    tf_data.user_data = 0;
    vpi_register_systf(&tf_data);
}

// vpi实现$pmem_read(addr, rdata)
/*=======================================================================*/
// vpi实现$pmem_write(waddr, wdata, wmask)

static int pmem_write_compiletf(char*user_data)
{
    (void)user_data; // Avoid a warning since user_data is not used.
    return 0;
}

static int pmem_write_calltf(char*user_data)
{
    (void)user_data; // Avoid a warning since user_data is not used.

	vpiHandle callh = vpi_handle(vpiSysTfCall, NULL);
	vpiHandle argv  = vpi_iterate(vpiArgument, callh);

	vpiHandle waddr_arg = vpi_scan(argv);
	s_vpi_value waddr_val;
	waddr_val.format = vpiVectorVal;
	vpi_get_value(waddr_arg, &waddr_val); // get data from Verilog.
    if (waddr_val.value.vector[0].bval != 0) {   // get X or Z status.
        vpi_printf("ERROR: Memory wtire address contains X/Z!\n");
        vpi_control(vpiFinish, 1);
        return 0;
    }
    uint32_t waddr = (uint32_t)waddr_val.value.vector[0].aval;

    vpiHandle wdata_arg = vpi_scan(argv);
	s_vpi_value wdata_val;
	wdata_val.format = vpiVectorVal;
	vpi_get_value(wdata_arg, &wdata_val); // get data from Verilog.
    // GPR允许硬件上不进行初始化
    // 在pmem_write()中对UART有效写入字节进行了X/Z检查
    // 因此不需要在这里禁止X/Z写数据
    
    uint32_t wdata = (uint32_t)wdata_val.value.vector[0].aval;
    uint32_t wdata_bval = (uint32_t)wdata_val.value.vector[0].bval;
    
    vpiHandle wmask_arg = vpi_scan(argv);
	s_vpi_value wmask_val;
	wmask_val.format = vpiVectorVal;
	vpi_get_value(wmask_arg, &wmask_val); // get data from Verilog.
    if (wmask_val.value.vector[0].bval != 0) {   // get X or Z status.
        vpi_printf("ERROR: Memory write mask contains X/Z!\n");
        vpi_control(vpiFinish, 1);
        return 0;
    }
    uint32_t wmask = (uint8_t)wmask_val.value.vector[0].aval;

    pmem_write(waddr, wdata, wdata_bval, wmask);

    return 0;
}

void pmem_write_register(void)
{
    s_vpi_systf_data tf_data;

    tf_data.type      = vpiSysTask;
    tf_data.tfname    = "$pmem_write";
    tf_data.calltf    = pmem_write_calltf;
    tf_data.compiletf = pmem_write_compiletf;
    tf_data.sizetf    = 0;
    tf_data.user_data = 0;
    vpi_register_systf(&tf_data);
}

// vpi实现$pmem_write(waddr, wdata, wmask)
/*=======================================================================*/
// vpi实现$pmem_load("program.bin")

static int pmem_load_compiletf(char*user_data)
{
    (void)user_data; // Avoid a warning since user_data is not used.
    return 0;
}

static int pmem_load_calltf(char*user_data)
{
    (void)user_data; // Avoid a warning since user_data is not used.

	vpiHandle callh = vpi_handle(vpiSysTfCall, NULL);
	vpiHandle argv  = vpi_iterate(vpiArgument, callh);

	vpiHandle bin_arg = vpi_scan(argv);
	s_vpi_value bin_val;
	bin_val.format = vpiStringVal;
	vpi_get_value(bin_arg, &bin_val); // get data from Verilog.

    FILE *fp = fopen(bin_val.value.str, "rb");
	if (fp == NULL) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }
	size_t bin_context = fread(pmem, 1, PMEM_SIZE, fp);

    return 0;
}

void pmem_load_register(void)
{
    s_vpi_systf_data tf_data;

    tf_data.type      = vpiSysTask;
    tf_data.tfname    = "$pmem_load";
    tf_data.calltf    = pmem_load_calltf;
    tf_data.compiletf = pmem_load_compiletf;
    tf_data.sizetf    = 0;
    tf_data.user_data = 0;
    vpi_register_systf(&tf_data);
}

/*=======================================================================*/

void (*vlog_startup_routines[])(void) = {
    pmem_read_register,
    pmem_write_register,
    pmem_load_register,
    0
};
