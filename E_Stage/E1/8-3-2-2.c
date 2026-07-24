#include <stdio.h>
#define N 4
#define M 2
int a[N] = {1, 2, 3, 4};        // 全局数组

void print_array(void)          // 打印当前数组中的前M个元素
{
    int i;
    for (i = 0; i < M; i++)
    {
        printf ("%d ", a[i]);
    }
    printf ("\n");
}

void swap_array(int i, int j)   // 交换数组中的2个元素
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int factorial(int n)            // 阶乘
{
    int i; 
    int fac = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            fac = fac * i;
        }
        return fac;
    }
}


void all_arrange(int begin)         // 全排列递归函数
{
    int i;

    if (begin == M) {               // 只要确定前M个位置
        print_array();
        return;                     // 结束一次递归，返回调用位置
    }

    for (i = begin; i < N; i++)      
    {  
        swap_array(begin, i);
        all_arrange(begin + 1);
        swap_array(begin, i);
    }
}


int main(void)
{
    all_arrange(0);

    return 0;
}
