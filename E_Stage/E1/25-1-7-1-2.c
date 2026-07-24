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

/* 参数str是待分割的字符串，delim是分隔符，saveptr记录下一次从哪里继续
   可以指定一个或多个分隔符，
   strtok遇到其中任何一个分隔符就会分割字符串。 */
char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *p;        // 扫描指针
    char *token;    // 找到的token

    if (str != NULL)
        p = str;
    else
        p = *saveptr;

    // 跳过开头连续的分隔符
    while (*p != '\0' && is_delim(*p, delim)) { 
        p++;
    }

    if (*p == '\0') {
        *saveptr = p;
        return NULL;
    }
    
    token = p;

    while (*p != '\0' && !is_delim(*p, delim))
        p++;

    if (*p != '\0') {
        *p = '\0';
        p++;
    }

    *saveptr = p;
    return token;
}

int main(void)
{
	char buf[] = "::abc:def;;ghi";
    char *saveptr, *token;

    for (token = my_strtok_r(buf, ":;", &saveptr);
         token != NULL;
         token = my_strtok_r(NULL, ":;", &saveptr)) {
        printf("%s\n", token);
    }

	return 0;
}