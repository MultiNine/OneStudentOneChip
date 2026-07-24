#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} query_pair;

typedef struct {
    char *path;
    query_pair *pairs;
    size_t pair_count;  // 记录pairs数组中保存多少个key=value键值对
} parsed_url;

void free_parsed_url(parsed_url *result)
{
    size_t i;

    if (result == NULL)
        return;

    for (i = 0; i < result->pair_count; i++) {
        free(result->pairs[i].key);
        free(result->pairs[i].value);
    }

    free(result->pairs);
    free(result->path);

    result->path = NULL;
    result->pairs = NULL;
    result->pair_count = 0;
}

/* 从start开始复制长度为len的字符串 */
char *copy_range(const char *start, size_t len)
{
    char* result = malloc(len + 1);
    if (result == NULL)
        return NULL;

    memcpy(result, start, len);
    result[len] = '\0';
    return result;
}

int parse_url(const char *url, parsed_url *result)
{
    // complete=1&hl=zh-CN&q=linux&meta=
    //            ↑    ↑
    //           key value

    const char *question;       // '?'的位置
    const char *query;          // '?'后第一个字符的位置
    const char *pair_start;
    const char *pair_end;
    const char *amp;            // 当前查询字符串中下一个'&'的位置
    const char *equal;          // 当前查询字符串中下一个'='的位置

    size_t path_len;
    size_t pair_len;
    size_t key_len;
    size_t value_len;
    size_t count;
    size_t i;

    char *key;
    char *value;

    if (url == NULL || result == NULL)
        return -1;

    result->path = NULL;
    result->pairs = NULL;
    result->pair_count = 0;

    /* 寻找路径和查询字符串之间的'?' */
    question = strchr(url, '?');
    if (question == NULL)
        return -1;

    path_len = question - url;
    if (path_len == 0)
        return -1;

    result->path = copy_range(url, path_len);
    if (result->path == NULL)
        return -2;

    query = question + 1;

    /* '?'后面不能为空 */
    if (*query == '\0') {
        free_parsed_url(result);
        return -1;
    }

    /* 检查每个键值对是否合法并统计数量键值对数量 */
    count = 0;
    pair_start = query;

    while (1) {
        amp = strchr(pair_start, '&');

        if (amp != NULL)
            pair_end = amp;
        else
            pair_end = pair_start + strlen(pair_start);

        pair_len = pair_end - pair_start;

        /* 出现连续的'&'或末尾的'&' */
        if (pair_len == 0) {
            free_parsed_url(result);
            return -1;
        }

        /* 只在当前键值对范围内寻找'=' */
        equal = memchr(pair_start, '=', pair_len);

        /* 没有'='或key为空 */
        if (equal == NULL || equal == pair_start) {
            free_parsed_url(result);
            return -1;
        }

        count++;    // 查找到一个键值对

        if (amp == NULL)
            break;

        pair_start = amp + 1;
    }

    /* 申请一块大小为count*sizeof(query_pair)的连续内存并初始化为0 */
    result->pairs = calloc(count, sizeof(query_pair));
    if (result->pairs == NULL) {
        free_parsed_url(result);
        return -2;
    }

    /* 分别复制每个key和value */
    pair_start = query;

    for (i = 0; i < count; i++) {
        amp = strchr(pair_start, '&');

        if (amp != NULL)
            pair_end = amp;
        else
            pair_end = pair_start + strlen(pair_start);

        pair_len = pair_end - pair_start;
        equal = memchr(pair_start, '=', pair_len);

        key_len = equal - pair_start;
        value_len = pair_end - (equal + 1);

        key = copy_range(pair_start, key_len);
        if (key == NULL) {
            free_parsed_url(result);
            return -2;
        }

        value = copy_range(equal + 1, value_len);
        if (value == NULL) {
            free(key);
            free_parsed_url(result);
            return -2;
        }

        result->pairs[i].key = key;
        result->pairs[i].value = value;

        /* 成功保存一项后再增加计数值 */
        result->pair_count++;

        if (amp == NULL)
            break;

        pair_start = amp + 1;
    }

    return 0;
}

int main(void)
{
    const char *url = "http://www.google.cn/search?complete=1&hl=zh-CN&q=linux&meta=";

    parsed_url result;
    int ret;
    size_t i;

    ret = parse_url(url, &result);

    if (ret == -1) {
        printf("Invalid URL format\n");
        return 1;
    }

    if (ret == -2) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("path = %s\n", result.path);

    for (i = 0; i < result.pair_count; i++) {
        printf("%s = %s\n",
               result.pairs[i].key,
               result.pairs[i].value);
    }

    free_parsed_url(&result);

    return 0;
}