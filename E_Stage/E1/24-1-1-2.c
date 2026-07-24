#include <stdio.h>

char *shrink_space(char *dest, const char *src, size_t n)
{
    char *ret = dest;       // 因为后续要改动dest，这里先保存最开始的dest指针方便后续返回
    size_t count = 0;       // 已写字节数

    while(*src != '\0') {
        if (count == n) {
            return ret;     // 写入字节数达到上限
        }

        if (*src == ' ' || *src == '\t' || *src == '\n' || *src == '\r') {
            *dest = ' ';
            dest++;
            count++;
            while (*src == ' ' || *src == '\t' || *src == '\n' || *src == '\r') {   
                src++;      // 连续空白字符跳过，不处理
            }
        }
        else {              // 非空白字符
            *dest = *src;
            dest++;
            src++;
            count++;
        }
    }

    if (count < n) {
        *dest = '\0';       // 最后要把dest字符串补全~
    }

    return ret;
}

int main(void)
{
    char src[] = "This Content hoho\tis ok\n\tok?\n\r\n\tfile system\nuttered words   ok ok\t?\nend.";
    char dest[sizeof(src)];
    size_t n = sizeof(dest);
    
    printf("%s\n", src);

    printf("%s", shrink_space(dest, src, n));

    return 0;
}