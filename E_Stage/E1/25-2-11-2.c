#include <stdio.h>
#include <string.h>

/* 删除字符串末尾的换行符 */
void remove_newline(char *str)
{
    while (*str != '\0') {
        if (*str == '\n') {
            *str = '\0';
            return;
        }
            
        str++;
    }
}

/* 删除字符串两端的空格和Tab */
char *trim(char *str)
{
    char *end;

    /* 跳过开头的空格和Tab */
    while (*str == ' ' || *str == '\t')
        str++;

    /* 找到字符串末尾 */
    end = str;
    while (*end != '\0')
        end++;

    /* 从末尾向前删除空格和Tab，end指向字符串末尾的'\0'，
       然后向前跳过空格和Tab，使用[-1]的下标指向末尾的前一个字符 */
    while (end > str && (end[-1] == ' ' || end[-1] == '\t'))
        end--;

    *end = '\0';

    return str;
}

int main(void)
{
    FILE *ini = fopen("25-2-11-2\\test.ini", "r");
    FILE *xml = fopen("25-2-11-2\\test.xml", "w");

    char line[100];
    char *p;

    char current_section[100] = ""; // 保存当前 Section 名；
    int section_open = 0;           // 记录是否已输出开始标签但还没输出结束标签

    // 依次读取ini文件中的一行，最大读取长度为sizeof(line)，将读取的内容存在line中
    while (fgets(line, sizeof(line), ini) != NULL) {    
        remove_newline(line);
        p = trim(line);                     // p为删除两端空格tab和末尾换行符后得到的字符串

        if (*p == '\0') {                   // 当前行为空行，结束当前Section
            if (section_open) {
                fprintf(xml, "</%s>\n\n", current_section);
                section_open = 0;
            }
        }
        else if (*p == ';') {               // 当前行为注释行
            char *comment = p + 1;
            fprintf(xml, "<!-- %s -->\n", comment);   
        }
        else if (*p == '[') {               // 当前行为Section开头
            char *section;            
            char *right = strchr(p, ']');
            if (right != NULL) {
                *right = '\0';
                section = p + 1;
            }

            strcpy(current_section, section);
            section_open = 1;
            fprintf(xml, "<%s>\n", current_section);
        }
        else if (strchr(p, '=') != NULL) {  // 当前行为键值对
            char *equal = strchr(p, '=');
            *equal = '\0';
            char *key = trim(p);
            char *value = trim(equal + 1);
            
            fprintf(xml, "      <%s>%s</%s>\n", key, value, key);
        }
    }

    if (section_open)
        fprintf(xml, "</%s>\n", current_section);   // 确保最后的Section结尾能被加上

    fclose(ini);
    fclose(xml);

    return 0;
}