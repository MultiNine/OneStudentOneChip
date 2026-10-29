/** WARNING: This code is fresh and potentially isn't correct yet. */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "dbg.h"

#define MAX_DATA 100

void my_printf(const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);

    for(int i = 0; fmt[i] != '\0'; i++) {
        if(fmt[i] == '%') {
            i++;
            switch(fmt[i]) {
                case 'c':
                    putchar(va_arg(argp, int));
                    break;

                case 'd': {
                    int num = va_arg(argp, int);
                    char buffer[32];
                    snprintf(buffer, sizeof(buffer), "%d", num);    // 将整数转换为十进制字符串并写入 buffer
                    fputs(buffer, stdout);
                    break;
                }

                case 's': {
                    char *str = va_arg(argp, char *);
                    fputs(str, stdout);
                    break;
                }
                    
                case '%':
                    putchar('%');
                    break;

                case '\0':
                    log_warn("Invalid format, you ended with %%.");
                    goto done;

                default:
                    log_warn("Invalid format: %%%c.", fmt[i]);
                    goto done;
            }
        } else {
            putchar(fmt[i]);
        }
    }

done:
    va_end(argp);
}

int read_string(char **out_string, int max_buffer)
{
    *out_string = calloc(1, max_buffer + 1);
    check_mem(*out_string);

    int ch;
    int i = 0;
    int too_long = 0;
    while((ch = fgetc(stdin)) != EOF && ch != '\n') {
        if(i < max_buffer - 1) {
            (*out_string)[i] = (char)ch;
            i++;
        } else {
            too_long = 1;
        }
    }
    (*out_string)[i] = '\0';
    check(too_long == 0, "Input too long.");

    return 0;

error:
    if(*out_string) free(*out_string);
    *out_string = NULL;
    return -1;
}

int read_int(int *out_int)
{
    char *input = NULL;
    int rc = read_string(&input, MAX_DATA);
    check(rc == 0, "Failed to read number.");

    *out_int = atoi(input);

    free(input);
    return 0;

error:
    if(input) free(input);
    return -1;
}

int read_scan(const char *fmt, ...)
{
    int i = 0;
    int rc = 0;
    int *out_int = NULL;
    char *out_char = NULL;
    char **out_string = NULL;
    int max_buffer = 0;

    va_list argp;
    va_start(argp, fmt);

    for(i = 0; fmt[i] != '\0'; i++) {
        if(fmt[i] == '%') {
            i++;
            switch(fmt[i]) {
                case '\0':
                    sentinel("Invalid format, you ended with %%.");
                    break;

                case 'd':
                    out_int = va_arg(argp, int *);
                    rc = read_int(out_int);
                    check(rc == 0, "Failed to read int.");
                    break;

                case 'c':
                    out_char = va_arg(argp, char *);
                    *out_char = fgetc(stdin);
                    break;

                case 's':
                    max_buffer = va_arg(argp, int);
                    out_string = va_arg(argp, char **);
                    rc = read_string(out_string, max_buffer);
                    check(rc == 0, "Failed to read string.");
                    break;

                default:
                    sentinel("Invalid format.");
            }
        } else {
            fgetc(stdin);
        }

        check(!feof(stdin) && !ferror(stdin), "Input error.");
    }

    va_end(argp);
    return 0;

error:
    va_end(argp);
    return -1;
}



int main(int argc, char *argv[])
{

    my_printf("Hello World!\n");
    my_printf("Number: %d\n", 123);
    my_printf("Negative: %d\n", -456);
    my_printf("Character: %c\n", 'A');
    my_printf("String: %s\n", "Alice");
    my_printf("Progress: 100%%\n");
    my_printf("%s is %d years old.\n", "Alice", 20);

    char *first_name = NULL;
    char initial = ' ';
    char *last_name = NULL;
    int age = 0;

    my_printf("What's your first name? ");
    int rc = read_scan("%s", MAX_DATA, &first_name);
    check(rc == 0, "Failed first name.");

    my_printf("What's your initial? ");
    rc = read_scan("%c\n", &initial);
    check(rc == 0, "Failed initial.");

    my_printf("What's your last name? ");
    rc = read_scan("%s", MAX_DATA, &last_name);
    check(rc == 0, "Failed last name.");

    my_printf("How old are you? ");
    rc = read_scan("%d", &age);
    check(rc == 0, "Failed age.");

    my_printf("---- RESULTS ----\n");
    my_printf("First Name: %s\n", first_name);
    my_printf("Initial: '%c'\n", initial);
    my_printf("Last Name: %s\n", last_name);
    my_printf("Age: %d\n", age);

    free(first_name);
    free(last_name);
    return 0;
error:
    return -1;
}