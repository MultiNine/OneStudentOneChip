#include <stdio.h>
#include <stdarg.h>

/* 输出一个非负整数 */
void print_unsigned(unsigned int n)
{
    char buf[20];
    int i = 0;

    if (n == 0) {
        putchar('0');
        return;
    }

    while (n != 0) {
        buf[i++] = n % 10 + '0';
        n /= 10;
    }

    while (i > 0)
        putchar(buf[--i]);
}

/* 输出一个有符号整数 */
void print_int(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    print_unsigned(n);
}

/* 输出浮点数，保留6位小数 */
void print_float(double n)
{
    int integer;
    int decimal;
    int divisor;

    if (n < 0) {
        putchar('-');
        n = -n;
    }

    integer = (int)n;
    decimal = (int)((n - integer) * 1000000 + 0.5);

    /* 小数四舍五入后可能向整数部分进位 */
    if (decimal == 1000000) {
        integer++;
        decimal = 0;
    }

    print_unsigned(integer);
    putchar('.');

    /* 固定输出6位小数 */
    divisor = 100000;
    while (divisor > 0) {
        putchar(decimal / divisor % 10 + '0');
        divisor /= 10;
    }
}

void myprintf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);

    while (*format != '\0') {
        if (*format != '%') {
            putchar(*format);
            format++;
            continue;
        }

        format++;  /* 跳过% */

        if (*format == 'd') {
            print_int(va_arg(ap, int));
        } else if (*format == 'f') {
            /* float传入可变参数时会提升为double */
            print_float(va_arg(ap, double));
        } else if (*format == 'c') {
            /* char传入可变参数时会提升为int */
            putchar(va_arg(ap, int));
        } else if (*format == '%') {
            putchar('%');
        } else {
            putchar('%');
            putchar(*format);
        }

        if (*format != '\0')
            format++;
    }

    va_end(ap);
}

int main(void)
{
    myprintf("num = %d\n", 123);
    myprintf("num = %d\n", -456);
    myprintf("pi = %f\n", 3.1415926);
    myprintf("character = %c\n", 'A');
    myprintf("rate = 80%%\n");

    return 0;
}