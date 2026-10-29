#include <stdio.h>
#include "dbg.h"

int read_file(const char *filename, char *buffer, size_t size)
{
    check(filename != NULL, "Invalid filename.");
    check(buffer != NULL, "Invalid buffer.");
    check(size > 0, "Invalid buffer size.");
    buffer[0] = '\0';

    FILE *fp = fopen(filename, "r");
    check(fp != NULL, "Failed to open file.");

    size_t i = 0;
    while(i < size - 1 && fscanf(fp, "%c", &buffer[i]) == 1) {
        i++;
    }
    buffer[i] = '\0';

    check(ferror(fp) == 0, "File read failed");
    fclose(fp);

    return i;

    error:
        return -1;
}

int main(int argc, char *argv[])
{
    char buffer[1];

    int n = read_file("ex24+4.txt", buffer, sizeof(buffer));

    printf("Read %d characters: %s\n", n, buffer);

    return 0;
}