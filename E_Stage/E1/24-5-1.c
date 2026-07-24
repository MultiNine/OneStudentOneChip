#include <stdio.h>

typedef int (*cmp_t)(void *, void *);

int cmp_int(void *a, void *b)
{
    int x = *(int *)a;  // 先强制类型转换为int*类型的指针，再取指针指向的值
    int y = *(int *)b;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    else
        return 0;
}

void insertion_sort(void *data[], int num, cmp_t cmp)
{
    int i, j;
    void *temp;

    for (i = 1; i < num; i++) {
        temp = data[i];
        j = i - 1;

        while (j >= 0 && (cmp(data[j], temp) > 0)) {
            data[j+1] = data[j];
            j--;
        }

        data[j+1] = temp;
    }
}

int main(void)
{
    int a[5] = {5, 1, 2, 4, 3};
    void *data[5];

    for (int i = 0; i < 5; i++) {
        data[i] = &a[i];
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(int *)data[i]);
    }

    printf("\n");

    insertion_sort(data, 5, cmp_int);

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(int *)data[i]);
    }

    return 0;
}