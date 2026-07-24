#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N];

void gen_random(int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
}

int howmany(int value)
{
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

int main(void)
{
	int i = 0, j = 0, k = 1;    // j表示当前是某一行的第几个字符，k表示当前打印的是第几行
    int count = 0;              // count为有效打印即*数，注意不要连同空格一起统计进去！
    int histogram[10] = {0};

	gen_random(10);
	for (i = 0; i < N; i++)
		histogram[a[i]]++;

    for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");

    printf("0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    while (count < N)
    {   
        for (j = 0; j < 10; j++)    // 1行打印10个字符
        {
            if (histogram[j] >= k)
            {
                printf("*");
                count++;
            } 
            else
            {
                printf(" ");
            }
            printf("\t");
        }
        printf("\n");
        k = k + 1;
    }

    return 0;
}