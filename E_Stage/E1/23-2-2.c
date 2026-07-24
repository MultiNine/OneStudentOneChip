#include <stdio.h>

void increment(int *x)
{
    int *temp = x;
    *temp = *temp + 1;
}

int main(void)
{
	int i = 1, j = 2;
	increment(&i); /* i now becomes 2 */
	increment(&j); /* j now becomes 3 */

    printf("now i = %d, j = %d",i, j);

	return 0;
}