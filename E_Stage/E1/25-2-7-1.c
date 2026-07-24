#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *src;
    FILE *dest;
    char buffer[BUFFER_SIZE];
    int status = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "Source and destination are the same file\n");
        return 1;
    }

    src = fopen(argv[1], "rb");
    if (src == NULL) {
        perror(argv[1]);
        return 1;
    }

    dest = fopen(argv[2], "wb");
    if (dest == NULL) {
        perror(argv[2]);
        fclose(src);
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, src) != NULL) {
        if (fputs(buffer, dest) == EOF) {
            perror("Write destination file");
            status = 1;
            break;
        }
    }

    if (ferror(src)) {
        perror("Read source file");
        status = 1;
    }

    return status;
}