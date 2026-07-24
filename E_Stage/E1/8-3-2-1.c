#include <stdio.h>
#define N 3
int a[N] = {1, 2, 3};        // 全局数组

void print_array(void)          // 打印当前数组中的全部元素
{
    int i;
    for (i = 0; i < N; i++)
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

/*
 all_arrange(begin)表示已经确定了a[0]到a[begin-1]的位置，现在要对a[begin]到a[N-1]做全排列。
 所以all_arrange(0)表示对整个数组做全排列。
 每一次递归让原来位置i的数，放到当前的begin位置。
 注意每一次递归之后要把交换的元素换回来，否则下一轮循环用到的数组就不是原来的状态，后面的排列会乱。
*/
void all_arrange(int begin)         // 全排列递归函数
{
    int i;

    if (begin == N) {               // 在一次递归中所有要交换的位置都已完成
        print_array();
        return;                     // 结束一次递归，返回调用位置
    }

    for (i = begin; i < N; i++)     // 以N=3为例，每个i下打印2种排列，一共3×2 = 3! = 6种全排列情况
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
