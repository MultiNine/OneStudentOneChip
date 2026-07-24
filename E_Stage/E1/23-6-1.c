#include <stdio.h>
int main(void)
{
    const char **p1;
    char *const *p2;
    char **const p3;

    **p1 = 'A';     // 错误，不能改写**p1指向的char类型变量
    **p2 = 'B';
    **p3 = 'C';

    *p1 = "abc";
    *p2 = "def";    // 错误，不能改写p2存储单元指向的值
    *p3 = "ghi";

    p1++;
    p2++;   
    p3++;           // 错误，不能修改p3的值

    return 0;
}