#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PMEM_BASE 0x80000000u
#define PMEM_SIZE (128 * 1024 * 1024)

uint32_t pmem[PMEM_SIZE / 4] = {0};

extern unsigned long long get_time();
extern "C" int pmem_read(int raddr) {
    if (raddr == 0x10000004) {              // 读出UART状态
        return (rand() & 0x7) == 0 ? 1 : 0; // 就绪概率为12.5%
    } else if (raddr == 0x20000000) {       // 读出时钟的低32位
        return get_time() & 0xffffffff; 
    } else if (raddr == 0x20000004) {       // 读出时钟的高32位
        return get_time() >> 32; 
    }

    int raddr_offset = raddr - PMEM_BASE;

    if (raddr_offset < 0 || raddr_offset >= PMEM_SIZE) {
        fprintf(stderr, "[PMEM READ ERROR] addr = 0x%08x\n", raddr);
        abort();
    }

    return pmem[(raddr_offset & ~0x3u) >> 2];
};

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    if (waddr == 0x10000000) {  // 写入UART
        fputc(wdata & 0xff, stderr);  
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