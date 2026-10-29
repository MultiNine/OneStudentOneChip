
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

enum State { IDLE, RUNNING };

int main(void)
{
    // 1. 基本数据类型
    int a = 10;
    const int b = 20;
    volatile int c = 30;
    register int d = 40;
    enum State state = RUNNING;
    void *ptr = &a;

    puts("=== Basic types ===");
    printf("char: %c, %zu bytes\n", 'A', sizeof(char));
    printf("short: %hd, %zu bytes\n", (short)10, sizeof(short));
    printf("int: %d, %zu bytes\n", a, sizeof(int));
    printf("long: %ld, %zu bytes\n", 100L, sizeof(long));
    printf("long long: %lld, %zu bytes\n", 100LL, sizeof(long long));
    printf("float: %f, %zu bytes\n", 3.14f, sizeof(float));
    printf("double: %f, %zu bytes\n", 3.14, sizeof(double));
    printf("long double: %Lf, %zu bytes\n", 3.14L, sizeof(long double));
    printf("signed char: %hhd, %zu bytes\n", (signed char)-10, sizeof(signed char));
    printf("unsigned int: %u, %zu bytes\n", 10U, sizeof(unsigned int));
    printf("const: %d, volatile: %d, register: %d\n", b, c, d);
    printf("enum: %d, void *: %p\n", state, ptr);

    // 2. 固定宽度整数
    puts("\n=== Fixed-width integers ===");
    printf("int8_t: %d, %zu bytes\n", (int)(int8_t)-8, sizeof(int8_t));
    printf("uint8_t: %u, %zu bytes\n", (unsigned int)(uint8_t)8, sizeof(uint8_t));
    printf("int16_t: %d, %zu bytes\n", (int)(int16_t)-16, sizeof(int16_t));
    printf("uint16_t: %u, %zu bytes\n", (unsigned int)(uint16_t)16, sizeof(uint16_t));
    printf("int32_t: %d, %zu bytes\n", (int)(int32_t)-32, sizeof(int32_t));
    printf("uint32_t: %u, %zu bytes\n", (unsigned int)(uint32_t)32, sizeof(uint32_t));
    printf("int64_t: %lld, %zu bytes\n", (long long)(int64_t)-64, sizeof(int64_t));
    printf("uint64_t: %llu, %zu bytes\n", (unsigned long long)(uint64_t)64, sizeof(uint64_t));

    // 3. 最小宽度和快速整数
    puts("\n=== Least and fast widths (8 / 16 / 32 / 64) ===");
    printf("int_least: %zu %zu %zu %zu bytes\n",
           sizeof(int_least8_t), sizeof(int_least16_t),
           sizeof(int_least32_t), sizeof(int_least64_t));

    printf("uint_least: %zu %zu %zu %zu bytes\n",
           sizeof(uint_least8_t), sizeof(uint_least16_t),
           sizeof(uint_least32_t), sizeof(uint_least64_t));

    printf("int_fast: %zu %zu %zu %zu bytes\n",
           sizeof(int_fast8_t), sizeof(int_fast16_t),
           sizeof(int_fast32_t), sizeof(int_fast64_t));

    printf("uint_fast: %zu %zu %zu %zu bytes\n",
           sizeof(uint_fast8_t), sizeof(uint_fast16_t),
           sizeof(uint_fast32_t), sizeof(uint_fast64_t));

    int_least16_t least = 100;
    int_fast16_t fast = 100;
    printf("int_least16_t example: %d\n", (int)least);
    printf("int_fast16_t example: %d\n", (int)fast);

    // 4. 其他整数类型和范围
    puts("\n=== Other types and limits ===");
    printf("intmax_t: %zu bytes, uintmax_t: %zu bytes\n",
           sizeof(intmax_t), sizeof(uintmax_t));

    printf("intptr_t: %zu bytes, uintptr_t: %zu bytes\n",
           sizeof(intptr_t), sizeof(uintptr_t));

    printf("size_t: %zu bytes, ptrdiff_t: %zu bytes\n",
           sizeof(size_t), sizeof(ptrdiff_t));

    printf("INT16_MIN = %d, INT16_MAX = %d\n", INT16_MIN, INT16_MAX);
    printf("UINT16_MAX = %u\n", (unsigned int)UINT16_MAX);
    printf("CHAR_BIT = %d\n", CHAR_BIT);

    return 0;
}
