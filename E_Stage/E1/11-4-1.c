#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
	// 从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
	// 在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
	// 使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
	// return mid;

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

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

int main(void)
{
    quicksort(0, LEN-1);
    printf("%d %d %d %d %d %d %d %d", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    
    return 0;
}