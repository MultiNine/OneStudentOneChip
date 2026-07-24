#include <stdio.h>
#include <stdlib.h>

typedef struct node *record;
struct node {
    int original_line;
    int year, month, day, hour, minute, second;
    record next;
};

/* 比较顺序是hour -> minute -> second -> year -> month -> day
    compare(a, b) < 0：a排在b前面
    compare(a, b) > 0：a排在b后面
    compare(a, b) = 0：日期、时间都相同                         */
int compare(record a, record b)
{
    if (a->hour != b-> hour)
        return a->hour - b->hour;
    if (a->minute != b-> minute)
        return a->minute - b->minute;
    if (a->second != b-> second)
        return a->second - b->second;
    if (a->year != b-> year)
        return a->year - b->year;
    if (a->month != b-> month)
        return a->month - b->month;
    
    /* 除了日期其他数字都相同 */
    return a->day - b->day;
}

int main(void)
{
    FILE *fp = fopen("test26-4-2.txt", "r");
    char line[100];
    record head = NULL;
    record p;           // 遍历链表指针

    while (fgets(line, sizeof(line), fp) != NULL) {
        record new_node = malloc(sizeof *new_node);
        sscanf(line, "%d %d-%d-%d %d:%d:%d",    // 注意sscanf应传入变量地址
               &new_node->original_line,
               &new_node->year, &new_node->month,  &new_node->day,
               &new_node->hour, &new_node->minute, &new_node->second);

        /* 对链表进行排序 */
        if (head == NULL || compare(new_node, head) < 0) {  // 在头部插入
            new_node->next = head;
            head = new_node;
        }
        else {  // 插入中间或末尾
            p = head;
            while (p->next != NULL && compare(p->next, new_node) <= 0)
                p = p->next;
            new_node->next = p->next;
            p->next = new_node;
        }
    }
        fclose(fp);
        FILE *newfp = fopen("test26-4-2.txt", "w"); // "w"清空文件进行写入
        int new_num = 1;
        p = head;
        
        while (p != NULL) {
            fprintf(newfp, "%d %d-%d-%d %02d:%02d:%02d\n",
                new_num,
                p->year, p->month, p->day,
                p->hour, p->minute, p->second);
            
            p = p->next;
            new_num++;
        }

    return 0;
}