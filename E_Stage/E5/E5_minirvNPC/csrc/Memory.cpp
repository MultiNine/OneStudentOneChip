#include <stdint.h>

uint32_t pmem[16] = {
    0x03c00513, 0x00052583, 0x09000613, 0x00c501a3,
    0x0ab00613, 0x00c50123, 0x0cd00613, 0x00c500a3,
    0x0ef00613, 0x00c50023, 0x00052683, 0x00100073,
    0x00000000, 0x00000000, 0x00000000, 0x12345678 
};

extern "C" int pmem_read(int raddr) {
    return pmem[(raddr & ~0x3u) >> 2];
};

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    int index    = (waddr & ~0x3u) >> 2;
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