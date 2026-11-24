#include <stdint.h>
#include <stdio.h>

#define GPIO_LED_ADDR       0x20001000u
#define GPIO_SWITCH_ADDR    0x20001004u
#define GPIO_SEG_ADDR       0x20001008u
#define DELAY_COUNT         500u

volatile uint32_t *led = (volatile uint32_t *)GPIO_LED_ADDR;
volatile uint32_t *sw  = (volatile uint32_t *)GPIO_SWITCH_ADDR;
volatile uint32_t *seg = (volatile uint32_t *)GPIO_SEG_ADDR;
uint32_t mvendorid;
uint32_t marchid;
uint64_t cycle;
uint32_t cyclel, cycleh;

int main() {
    // while (*sw != 0x159d) {
        // wait for correct password
    // }

    asm volatile ("csrr %0, mvendorid" : "=r"(mvendorid));
    asm volatile ("csrr %0, marchid" : "=r"(marchid));
    printf("the value of mvendorid is %08x\n", mvendorid);
    printf("the value of marchid is %08x\n", marchid);

    *seg = 0x05f63b08;

    uint32_t pattern = 1;
    volatile uint32_t cnt = 0;
    *led = pattern;
    while (1) {
        cnt++;
        if (cnt >= DELAY_COUNT) {
            cnt = 0;

            asm volatile ("csrr %0, mcycle" : "=r"(cyclel));
            asm volatile ("csrr %0, mcycleh" : "=r"(cycleh));
            cycle = ((uint64_t)cycleh << 32) | cyclel;
            printf("current cycle is %llu\n", cycle);

            pattern <<= 1;
            // printf("led shift\n");
            if (pattern > 0x8000) {
                pattern = 1;
            }
            *led = pattern;
        }
    }
    return 0;
}