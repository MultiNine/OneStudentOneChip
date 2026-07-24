#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0)
    {
        return a;
    }
    while (a % b != 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int main()
{
    int a = -48;
    int b = 18;

    printf("gcd is %d", gcd(a, b));

    return 0;
}