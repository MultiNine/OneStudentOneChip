#include <stdio.h>

int diamond(int n, char ch)
{
    int i, j, k;
    if (n % 2 == 0)
    {
        printf("Error, please input odd number.");
        return 1;
    }

    /* 打印上半部分 */
    for(i = 1; i <= (n+1)/2; i = i+1)           // 一共有(n+1)/2行要打印，i这里表示行号
    {
        for (j = 1; j <= (n+1)/2-i; j = j+1)    // 打印制表符，每行(n+1)/2-i个
        {
            printf("\t");
        }
        for (k = 1; k <= 2*i-1; k = k+1)        // 打印"符号+制表符"，每行2*i-1个
        {
            printf("%c\t", ch);                 // 注意后面也有一个制表符
        }
        printf("\n");
    }

    /* 打印下半部分 */
    for(i = 1; i <= (n+1)/2-1; i = i+1)         // 一共有(n+1)/2-1行要打印，i这里表示行号
    {
        for (j = 1; j <= i; j = j+1)            // 打印制表符，每行i个
        {
            printf("\t");
        }
        for (k = 1; k <= n-2*i; k = k+1)        // 打印"符号+制表符"，每行n-2*i个
        {
            printf("%c\t", ch);                 // 注意后面也有一个制表符
        }
        printf("\n");
    }

    return 0;
}

int main(void)
{
	diamond(3, '+');
	return 0;
}