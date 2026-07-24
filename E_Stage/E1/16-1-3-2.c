#include <stdio.h>

//          11011
//         ¡Á10010
//         ------
//          00000
//         11011   ---> 11011 ¡Á2  (<<1)
//        00000
//       00000
//      11011      ---> 11011 ¡Á16 (<<4)
//   -------------
// = ((11011)<<1)+((11011)<<4)

unsigned int multiply(unsigned int x, unsigned int y)
{   
    unsigned int result = 0;
    unsigned int shiftnum = 0;

    while (y != 0) {
        if (y % 2 == 1) {
            result = result + (x << shiftnum);
        }
        shiftnum = shiftnum + 1;
        y = y / 2;
    }
    return result;
}

int main(void)
{
    unsigned int x, y;
    x = 27; /* 11011 */
    y = 18; /* 10010 */

    printf("%d * %d = %d", x, y, multiply(x, y));

    return 0;
}

