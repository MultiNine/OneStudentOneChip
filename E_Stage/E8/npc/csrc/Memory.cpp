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

extern unsigned long long get_time();

extern "C" int pmem_read(int raddr) {
    if (raddr == 0x10000005) {              // 读出UART状态
        return 0x00002000;                  // 发送就绪状态LSR[5]=1
    } else if (raddr == 0x20000000) {       // 读出时钟的低32位
        return get_time() & 0xffffffff; 
    } else if (raddr == 0x20000004) {       // 读出时钟的高32位
        return get_time() >> 32; 
    }

    int raddr_offset = raddr - PMEM_BASE;

    if (raddr_offset < 0 || raddr_offset >= PMEM_SIZE) {
        return 0x00000000;
    }

    return pmem[(raddr_offset & ~0x3u) >> 2];
};

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    
    uint32_t addr = (uint32_t)waddr;
    if (addr >= UART_BASE && addr < UART_END) {
        uint32_t offset = addr - UART_BASE;
        uint32_t lane = addr & 0x3;     // 取访问地址低2位
        uint8_t data = ((uint32_t)wdata >> (lane * 8)) & 0xff;  // 从32位写数据中提取实际写入的8位数据
        // 操作UART寄存器
        if (offset == 0x3) {        // access LCR
            uart_lcr = data;
        }
        else if (offset == 0x1) {   // access DLM
            if (uart_lcr & 0x80) {  // LCR[7] == 1
                uart_dlm = data;
            }
        }
        else if (offset == 0x0) {   // access DLL or THR
            if (uart_lcr & 0x80) {  // LCR[7] == 1
                uart_dll = data;
            } else {
                fputc(data, stderr);
            }
        }
        return;
    }
    
    int waddr_offset = waddr - PMEM_BASE;
    int index    = (waddr_offset & ~0x3u) >> 2;
    int old_data = pmem[index];
    int byte_mask = 0x0u;
    
    for (int i = 0; i < 4; i++) {
        if (wmask & (0x1u << i)) {
            byte_mask |= (0xffu << (i * 8));
        }
    }

    wdata = (old_data & ~byte_mask) | (wdata & byte_mask);
    
    pmem[index] = wdata;
};