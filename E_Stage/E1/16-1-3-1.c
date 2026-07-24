#include <stdio.h>

// 26829 = 0110_1000_1100_1101
int countbit(unsigned int x)
{   
    int remain, cnt = 0;
    while (x != 0) {
        remain = x % 2;
        if (remain == 1)
            cnt++;
        x = x / 2;
    }

    return cnt;
}

int main(void)
{
    int x = 26829;
    printf("the number of 1s in %d is %d", x, countbit(x));

    return 0;
}