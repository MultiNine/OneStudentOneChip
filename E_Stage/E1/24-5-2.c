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

void *binary_search(void *key, void *data[], int num, cmp_t cmp)
{
    int start = 0;
    int end = num - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int result = cmp(data[mid], key);

        if (result < 0)         // 要找的数在右边
            start = mid + 1;
        else if (result > 0)    // 要找的数在左边
            end = mid - 1;
        else
            return data[mid];
    }

    return NULL;
}

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    void *data[5], *result;
    int key = 4;

    for (int i = 0; i < 5; i++)
        data[i] = &a[i];

    result = binary_search(&key, data, 5, cmp_int);

    if (result != NULL)
        printf("找到，位置在：%d\n", *(int *)result);
    else
        printf("没有找到\n");

    return 0;
}