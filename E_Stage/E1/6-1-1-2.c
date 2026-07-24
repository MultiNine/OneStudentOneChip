#include <stdio.h>

int fib(int n)
{
    int prev = 1;   // fib(0) == 1
    int curr = 1;   // fib(1) == 0
    int next = 0;
    int i    = 2;   // 已知fib(0)和fib(1)，循环从fib(2)开始计算

    if (n == 0 || n == 1)
    {
        return 1;
    }

    while (i <= n)
    {
        next = prev + curr;
        prev = curr;
        curr = next;
        i = i + 1;
    }
    return curr;
}

int main()
{
    int n = 0;

    printf("fib(%d) = %d\n", n, fib(n));

    return 0;
}