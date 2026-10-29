#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0, j = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;  // watch for this
    j = 1;

    while(j < argc && i < num_states ) {
        states[i] = argv[j];
        i++;
        j++;
    }

    i = 0;
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    printf("argv[1] address: %p\n", (void *)argv[1]);
    printf("states[0] address: %p\n", (void *)states[0]);

    return 0;
}