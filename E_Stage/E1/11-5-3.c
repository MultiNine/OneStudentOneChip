#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

// 执行1次partition的时间复杂度为O(n)
int partition(int start, int end)
{
    int pivot = a[start];
    
    while (start < end) {
        while (start < end && a[end] >= pivot) {
            end--;
        }
        a[start] = a[end];

        while (start < end && a[start] <= pivot) {
            start++;
        }
        a[end] = a[start];
    }
    a[start] = pivot;

    return start;
}

/* 从start到end之间找出第k小的元素 */
int order_statistic(int start, int end, int k)
{
    if (start == end) {
    return a[start];
}

    // mid为pivot所在的数组下标
    // i为当前区间里第i小的数
    // k为要找当前区间里的第k小的数
    int mid, i;
    mid = partition(start, end);
    i = mid - start + 1;    // 注意当前区间从start而不一定是0开始

	if (k == i) {           // 返回找到的元素;
        return a[mid];
    }
	else if (k > i) {       // 从后半部分找出第k-i小的元素并返回;
        return order_statistic(mid+1, end, k-i);
    }
	else {                  // 从前半部分找出第k小的元素并返回;
        return order_statistic(start, mid-1, k);
    }                
}

int main(void)
{
    int k = 4;
    int result = order_statistic(0, LEN-1, k);
    printf("第%d小的数为%d ", k, result);
    
    return 0;
}