#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
        ' ', 'A', '.', ' ',
        'S', 'h', 'a', 'w', '\0'
    };

    areas[0] = 100;
    areas[1] = 200;
    areas[2] = name[0];

    name[0] = 'A';
    name[1] = 'n';
    name[2] = 'n';

    full_name[4] = 'B';

    printf("The first area is %d, the 2nd %d, the 3rd %d.\n",
            areas[0], areas[1], areas[2]);
    
    printf("name=\"%s\" and full_name=\"%s\"\n",
            name, full_name);
    

    return 0;
}