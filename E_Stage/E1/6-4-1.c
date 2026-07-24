#include <stdio.h>

int is_prime(int n)
{
	int i = 2;  // 给i初值2，避免n=1时错误返回1，同时确保i=2时返回1
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	if (i == n)
		return 1;
    else
        return 0;
}

int main(void)
{
	int i;
	for (i = 1; i <= 100; i++) {
		if (is_prime(i))
		    printf("%d\n", i);
	}
	return 0;
}