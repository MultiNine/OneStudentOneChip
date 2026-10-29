#include <stdio.h>

int main(int argc, char *argv[])
{
    // if(argc != 2) {
    //     printf("ERROR: You need one argument.\n");
    //     // this is how you abort a program
    //     return 1;
    // }

    int i, j;
    char letter;
    for(i = 1; i < argc; i++)
    {
        for(j = 0, letter = argv[i][0]; argv[i][j] != '\0'; j++, letter = argv[i][j]) {

            if(letter >= 'A' && letter <= 'Z') {
                letter = letter + ('a' - 'A');
            }

            if (letter == 'a') {
                printf("[%d, %d]: 'A'\n", i, j);
            } else if(letter == 'e') {
                printf("[%d, %d]: 'E'\n", i, j);

            } else if(letter == 'i') {
                printf("[%d, %d]: 'I'\n", i, j);
                
            } else if(letter == 'o') {
                printf("[%d, %d]: 'O'\n", i, j);
                
            } else if(letter == 'u') {
                printf("[%d, %d]: 'U'\n", i, j);
            } else if(letter == 'y') {
                if(j > 2) {
                   printf("[%d, %d]: 'Y'\n", i, j);
                }
            } else{
                printf("[%d, %d]: %c is not a vowel\n", i, j, argv[i][j]);
            }

        }
    }

    return 0;
}