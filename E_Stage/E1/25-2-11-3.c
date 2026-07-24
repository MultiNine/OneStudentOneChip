#include <stdio.h>
#include <string.h>

char system_dir[200] = "E:\\MinGW\\include";
char source_dir[200];
char visited[100][200];
int visited_num = 0;

/* 从一行中提取头文件名 */
int parse_include(char *line, char *header, char *type)
{
    char *p = line;
    char *end;
    char right;
    int len;

    /* 跳过行首行中空格和Tab  #   include  <stdio.h> */
    while (*p == ' ' || *p == '\t')
        p++;
        
    if (*p != '#')
        return 0;
    else
        p++;
        
    while (*p == ' ' || *p == '\t')
        p++;

    if (strncmp(p, "include", 7) != 0)
        return 0;
    else
        p += 7;

    while (*p == ' ' || *p == '\t')
        p++;

    if (*p == '<')
        right = '>';
    else if (*p == '"')
        right = '"';
    else
        return 0;

    *type = *p;
    p++;

    end = strchr(p, right);
    if (end == NULL)
        return 0;

    len = end - p;

    if (len <= 0 || len >= 200)
        return 0;

    /* memcpy不关心字符串末尾的'\0'，如果写strcpy(header, p);
       会一直复制到原来这一行末尾的 '\0'，
       得到stdio.h，甚至还会包含换行符 */
	memcpy(header, p, len);  
    header[len] = '\0';

    return 1;
}

/* 判断文件是否存在，找不到返回0 */
int try_file(char *path, char *fullpath)
{
    FILE *fp;

    fp = fopen(path, "r");
    if (fp == NULL)
        return 0;

    fclose(fp);

    strcpy(fullpath, path);

    return 1;
}

/* 按规定的顺序查找头文件 */
int find_header(char *header, char type, char *fullpath, char *failed_path)
{
    char path[200];
    int len;

    /* "..."先在.c文件所在目录查找 */
    if (type == '"') {
        len = snprintf(path, sizeof(path), "%s\\%s",
                       source_dir, header);

        if (len < 0 || len >= sizeof(path))
            return 0;

        strcpy(failed_path, path);

        if (try_file(path, fullpath))
            return 1;
    }

    /* <...>在MinGW目录查找。
       "..."在源文件目录中找不到时也在MinGW目录查找 */
    len = snprintf(path, sizeof(path), "%s\\%s",
                   system_dir, header);

    if (len < 0 || len >= sizeof(path))
        return 0;

    if (type == '<')
        strcpy(failed_path, path);

    if (try_file(path, fullpath))
        return 1;

    return 0;
}

/* 判断文件是否已经扫描过 */
int is_visited(char *path)
{
    int i;

    for (i = 0; i < visited_num; i++) {
        if (strcmp(visited[i], path) == 0)
            return 1;
    }

    return 0;
}

/* 记录已经扫描过的文件，最多记录100个 */
int add_visited(char *path)
{
    if (visited_num >= 100)
        return 0;

    strcpy(visited[visited_num], path);
    visited_num++;

    return 1;
}

/* 递归扫描文件 */
void scan_file(char *filename)
{
    FILE *fp;
    char line[1000];
    char header[200];
    char fullpath[200];
    char failed_path[200];
    char type;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s: cannot open\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (!parse_include(line, header, &type))
            continue;

        /* 避免failed_path没有初始化 */
        strcpy(failed_path, header);

        if (!find_header(header, type,
                         fullpath, failed_path)) {
            printf("%s: cannot find\n", failed_path);
            continue;
        }

        /* 已经扫描过则不重复处理 */
        if (is_visited(fullpath))
            continue;

        printf("%s\n", fullpath);

        /* 在递归前记录，避免头文件相互包含时无限递归 */
        if (!add_visited(fullpath)) {
            printf("too many header files\n");
            fclose(fp);
            return;
        }

        scan_file(fullpath);
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char source_path[200];
    char *last_separator;

    if (argc != 2) {
        printf("Usage: %s absolute-path-of-file.c\n", argv[0]);
        return 1;
    }

    if (strlen(argv[1]) >= sizeof(source_path)) {
        printf("path is too long\n");
        return 1;
    }

    strcpy(source_path, argv[1]);

    /* 检查输入文件是否存在 */
    fp = fopen(source_path, "r");
    if (fp == NULL) {
        printf("%s: cannot open\n", source_path);
        return 1;
    }

    fclose(fp);

    /* 找出路径中的最后一个分隔符 */
    last_separator = strrchr(source_path, '\\');

    if (last_separator == NULL) {
        printf("cannot get source directory\n");
        return 1;
    }

    /* 提取.c文件所在目录 */
    *last_separator = '\0';
    strcpy(source_dir, source_path);
    *last_separator = '\\';

    /* 将.c文件本身记录为已经扫描 */
    if (!add_visited(source_path)) {
        printf("cannot add source file\n");
        return 1;
    }

    scan_file(source_path);

    return 0;
}