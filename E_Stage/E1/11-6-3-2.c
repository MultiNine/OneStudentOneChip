/* 用循环实现 */
#include <stdio.h>

double mypow(double x, int n) // return x^n
{
    double result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = result * x;    // 即使n为偶数最后也会执行1次
        }
        x = x * x;
        n = n / 2;
    }
    return result;
    
}

int main(void)
{
    double x = 2.9;
    int n = 13;

    printf("%f^%d = %f", x, n, mypow(x, n));

    return 0;
}