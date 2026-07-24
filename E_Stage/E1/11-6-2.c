#include <stdio.h>

double mysqrt(double y)
{
    if (y <= 0)
        return -1.0;
    
    double x = y / 2.0;
    double top;
    double bot = 0;
    while ( (x * x - y >= 0.001) || (x * x - y <= -0.001) ) {

        if (x * x -  y > 0) {   // 结果在左边
            top = x;
            x = (bot + top) / 2.0;
        }
        else {                  // 结果在右边
            bot = x;
            x = (bot + top) / 2.0;
        }
    }
    return x;
}


int main(void)
{
    double a = 2.0;
    printf("sqrt %f is %f", a, mysqrt(a));
    
    return 0;
}