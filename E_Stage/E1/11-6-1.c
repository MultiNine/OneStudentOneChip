#include <stdio.h>
#define LEN 8
int a[LEN] = { 1, 2, 2, 2, 5, 6, 8, 9 };

int binarysearch(int number)
{
	int start = 0;
	int end = LEN - 1;
    int result = -1;

	while (start <= end)			// 注意不能写成 start < end !!
	{
		int mid = (start + end) / 2;
        
		if (a[mid] < number)		// 要找的数在右边
			start = mid + 1;
		else if (a[mid] > number)	// 要找的数在左边
			end = mid - 1;
		else {
            result = mid;
            end = mid - 1;
        }
	}
	    return result;						
}

int main(void)
{
	printf("%d\n", binarysearch(2));
	return 0;
}