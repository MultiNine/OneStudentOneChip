#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 0;
    void *p;

    while ((p = malloc(102400)) != NULL) {
        count += 1;
        printf("count = %d\n", count);
    }

    printf("count = %d\n", count);
    
}