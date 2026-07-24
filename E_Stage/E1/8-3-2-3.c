#include <stdio.h>
#define N 6
#define M 3
int a[N] = {1, 2, 3, 4, 5, 6};  // 全局数组
int b[N] = {0};                 // 保存组合结果的全局数组

void print_array(void)          // 打印当前数组中的前M个元素
{
    int i;
    for (i = 0; i < M; i++)
    {
        printf ("%d ", b[i]);
    }
    printf ("\n");
}

void combine(int position, int count)   // 组合递归函数，现在正在考虑a[pos]这个数，目前已经选了count个数。
{ 
    if (count == M)     // 已经选够所需的M个数
    {
        print_array();
        return;
    }
    if (position == N)  // 失败
    {
        return;
    }

    /* 选择当前数放入b[N] */
    b[count] = a[position];
    combine(position + 1, count + 1);

    /* 不选择当前数 */
    combine(position + 1, count);
}

int main(void)
{
    combine(0, 0);

    return 0;
}