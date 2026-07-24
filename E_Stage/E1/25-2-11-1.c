#include <stdio.h>
#include <time.h>
#include <windows.h>    // Sleep函数所需

int main(void)
{
    int last_num = 0;
    int num;
    char line[100];

    FILE *fp = fopen("test.txt", "r");

    /* 获取文件中最后一行的行号 */
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp) != NULL)   // 成功读到一行就继续循环；到文件末尾或读取失败时结束
        {
            if (sscanf(line, "%d", &num) == 1)  // 从line开头解析一个整数,成功读取时sscanf返回1
                last_num = num;
        }

        fclose(fp);
    }
    printf("last_num = %d\n", last_num);

    /* 在文件末尾追加写入内容 */
    fp = fopen("test.txt", "a");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    while (1) {
        last_num++;

        /* 获取当前时间 */
        time_t now;
        struct tm *local_time;

        now = time(NULL);               // 获取当前时间，保存为time_t类型
        local_time = localtime(&now);   // 把获取的时间转换成年月日时分秒存在local_time结构体中

        /* 写入文件 */
        fprintf(fp, "%d %d-%d-%d %02d:%02d:%02d\n",
                last_num,                               // 行号
                local_time->tm_year + 1900,             // tm_year值为1900年到现在经过的年份
                local_time->tm_mon + 1,                 // tm_mon的范围是0～11，所以要+1
                local_time->tm_mday,
                local_time->tm_hour,
                local_time->tm_min,
                local_time->tm_sec);
        fflush(fp);

        Sleep(1000);    // 1000ms对应1s
    }

    return 0;
}