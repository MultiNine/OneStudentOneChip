#include <stdio.h>

char *strcpy(char *dest, char *src)
{
    char *p = dest;
    while ( (*p++ = *src++) != '\0' );
    return dest;
}

int main(void)
{
    char dest[10];
    char src[6] = "hello";

    printf("%s", strcpy(dest, src));

    return 0;
}