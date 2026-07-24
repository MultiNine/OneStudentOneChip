#include <stdio.h>

int main(void)
{
    char ch;
    printf("Before getchar\n");

    ch = getchar();

    printf("After getchar: ch = %c\n", ch);

    return 0;
}