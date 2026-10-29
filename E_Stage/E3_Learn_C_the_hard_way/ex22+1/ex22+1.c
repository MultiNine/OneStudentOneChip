#include <stdio.h>

void change_value(int x)
{
    x = 100;
}
void change_pointer(int *x)
{
    *x = 100;
}

int main()
{
    int a = 10;
    int b = 20;
    printf("a before change_value: %d\n", a);
    printf("b before change_pointer: %d\n", b);

    change_value(a);
    change_pointer(&b);

    printf("a after change_value: %d\n", a);
    printf("b after change_pointer: %d\n", b);

    return 0;
}