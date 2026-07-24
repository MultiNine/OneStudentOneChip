#include <stdio.h>
int main()
{
    int i;
    int a[] = {1, 2, 3, 4, 5};
    int b[5] = {0};

    for (i = 0; i < 5; i++)
		printf("b[%d]=%d\n", i, b[i]);

    for (i = 0; i < 5; i++)
		b[i] = a[i];

    for (i = 0; i < 5; i++)
		printf("the new b[%d]=%d\n", i, b[i]);

	return 0;
}