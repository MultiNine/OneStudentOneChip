#include <stdio.h>
#include <string.h>

/* .\mycp.exe dir1\fileA dir2\fileB 
        ↑         ↑          ↑       
     argv[0]  argv[1]      argv[2] 
     程序名 源文件路径  目标文件路径 */
int main(int argc, char *argv[])
{
    FILE *src;
    FILE *dest;
    int ch;
    int status = 0;

    /* 检查命令行参数数量 */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        return 1;
    }

    /* 检查两个路径字符串是否完全相同 */
    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "Source and destination are the same file\n");
        return 1;
    }

    src = fopen(argv[1], "rb");     // 二进制只读方式打开
    if (src == NULL) {
        perror(argv[1]);            // 找不到文件
        return 1;
    }

    dest = fopen(argv[2], "wb");    // 二进制写方式打开
    if (dest == NULL) {
        perror(argv[2]);            // 目标文件打开失败
        fclose(src);
        return 1;
    }

    /* 逐字节复制 
       ch定义为int型，因为ch除保存一个字节外还需能保存返回值EOF */
    while ((ch = fgetc(src)) != EOF) {  
        if (fputc(ch, dest) == EOF) {           // fputc把读取的字节写入目标文件
            perror("Write destination file");
            status = 1;
            break;
        }
    }

    /* fgetc()返回EOF有正常读到文件末尾和读文件时发生错误两种情况 
       要进行区分                                                 */
    if (ferror(src)) {
        perror("Read source file");
        status = 1;
    }

    // 最后再进行返回，返回非0说明执行出错
    return status;
}