#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (b == 0)
        return a;
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main(void)
{
	int a = -48;
    int b = 18;
    printf("gcd is %d", gcd(a, b));
	return 0;
}