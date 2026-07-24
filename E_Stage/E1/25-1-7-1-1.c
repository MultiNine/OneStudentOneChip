#include <stdio.h>

// 判断字符是否为分隔符
int is_delim(char c, const char *delim)
{
    while (*delim != '\0') {
        if (c == *delim)
            return 1;
        delim++;
    }

    return 0;
}

char *my_strtok(char *str, const char *delim)
{
    static char *saveptr;

    char *p;        // 扫描指针
    char *token;    // 找到的token

    if (str != NULL)
        p = str;
    else
        p = saveptr;

    // 跳过开头连续的分隔符
    while (*p != '\0' && is_delim(*p, delim)) { 
        p++;
    }

    if (*p == '\0') {
        saveptr = p;
        return NULL;
    }
    
    token = p;

    while (*p != '\0' && !is_delim(*p, delim))
        p++;

    if (*p != '\0') {
        *p = '\0';
        p++;
    }

    saveptr = p;
    return token;
}

int main(void)
{
	char buf[] = "::abc:def;;ghi";
    char *token;

    for (token = my_strtok(buf, ":;");
         token != NULL;
         token = my_strtok(NULL, ":;")) {
        printf("%s\n", token);
    }

	return 0;
}