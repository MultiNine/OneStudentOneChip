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

            switch(letter) {
                case 'a':
                    printf("[%d, %d]: 'A'\n", i, j);
                    break;
            
                case 'e':
                    printf("[%d, %d]: 'E'\n", i, j);
                    break;
            
                case 'i':
                    printf("[%d, %d]: 'I'\n", i, j);
                    break;
            
                case 'o':
                    printf("[%d, %d]: 'O'\n", i, j);
                    break;
            
                case 'u':
                    printf("[%d, %d]: 'U'\n", i, j);
                    break;
            
                case 'y':
                    if(j > 2) {
                        // it's only sometimes Y
                        printf("[%d, %d]: 'Y'\n", i, j);
                    }
                    break;
                default:
                    printf("[%d, %d]: %c is not a vowel\n", i, j, argv[i][j]);
                    break;
            }
        }
    }

    return 0;
}