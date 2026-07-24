#include <stdio.h>
#include <math.h>

double myround(double x)
{
    if (x < 0)
    {
        if (ceil(x) - x >= 0.5)
            return (floor(x));
        else
            return (ceil(x));
    }
    else
    {
        if (ceil(x) - x >= 0.5)
            return (floor(x));
        else
            return (ceil(x));
    }
}

int main(void)
{
    double x = -3.51;
    double y = 4.49;
    double resultx, resulty;

    resultx = myround(x);
    resulty = myround(y);
    printf("resultx = %f, resulty = %f", resultx, resulty);

    return 0;
}