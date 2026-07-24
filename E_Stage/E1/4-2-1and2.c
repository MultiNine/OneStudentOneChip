// 写两个表达式，分别取整型变量x的个位和十位。
// ones = x % 10;
// tens = x / 10;

#include <stdio.h>

// 写一个函数，参数是整型变量x，功能是打印x的个位和十位。
void onesANDtens(int x)
{
    int ones = x % 10;
    int tens = x / 10 % 10; // 先去除个位再取模即为十位
    printf("ones = %d, tens = %d", ones, tens);
}

int main(void)
{
    int x = 10086;
    onesANDtens(x);

    return 0;
}
