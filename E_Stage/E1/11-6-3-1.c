/* ”√µ›πÈ µœ÷ */
#include <stdio.h>

double mypow(double x, int n) // return x^n
{   
    if (n == 0)
        return 1;

    double half = mypow(x, n / 2);

    if (n % 2 == 0) {
        return half * half;
    }
    else {
        return half * half * x;
    }
    
}

int main(void)
{
    double x = 2.9;
    int n = 13;

    printf("%f^%d = %f", x, n, mypow(x, n));

    return 0;
}