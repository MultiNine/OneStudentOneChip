#include <stdio.h>

int main()
{
    int num = 0;
    int i = 1;
    int ones, tens, hundreds;

    while (i <= 100)
    {
        ones = i % 10;
        tens = i / 10 % 10;
        hundreds = i / 10 / 10 % 10;
        
        if (ones == 9)
            num = num + 1;
        if (tens == 9)
            num = num + 1;
        if (hundreds == 9)
            num = num + 1;

        i = i + 1;
    }

    printf("the number of 9 form 1 to 100 is %d\n", num);

    return 0;
}