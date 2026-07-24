#include <stdio.h>

unsigned int rotate_right(unsigned int x, int n)
{   
    unsigned int result, mask = 0;
    unsigned int lown;
    int i;

    n = n % 32;
    
    if (n == 0)
        return x;
    
    for (i = 0; i < n; i++) {
        mask = (mask << 1) + 1;
    }

    lown = x & mask;
    result = (lown << (32 - n)) | (x >> n);

    return result;
}

int main(void)
{
    unsigned int x = 0xdeadbeef;
    int n = 8;

    printf("%x rotate right %d bit is %x", x, n, rotate_right(x, n));

    return 0;
}

