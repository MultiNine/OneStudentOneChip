#include <stdio.h>
#include <stdlib.h>

typedef struct node *people;
struct node {
    int num;
    people next;
};

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s N M\n", argv[0]);
        return 1;
    }

    int i;
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    people head = NULL;
    people tail = head;
    people curr, prev;

    /* 创建长度为N的环形链表 */
    for (i = 1; i <= N; i++) {
        people new_node = malloc(sizeof *new_node);
        new_node->num = i;
        new_node->next = NULL;
        if (head == NULL) {
            /* 第一个节点既是头节点，也是尾节点 */
            head = new_node;
            tail = new_node;
        } else {
            /* 把新节点接到尾节点后面 */
            tail->next = new_node;
            tail = new_node;
        }
    }
    /* 让最后一个节点重新指向第一个节点 */
    tail->next = head;

    /* 进行淘汰 */
    curr = head;     // 从1号开始报数
    prev = tail;     // 1号的前一个人是N号
    while (curr->next != curr) {  // 至少还有2个人
        /* 数M个人，即向后移动M-1次 */
        for (i = 1; i <= M-1; i++) {
            prev = curr;        // prev指向curr
            curr = curr->next;  // curr指向下一位
        }

        printf("%d is killed\n", curr->num);

        /* 删除被淘汰者，注意prev指向的目标没变 
           A->victim->C => A-->C
           ↑     ↑         ↑   ↑
         prev  curr      prev curr              */
        people victim = curr;
        prev->next = curr->next;
        curr = curr->next;
        free(victim);
    }

    printf("%d is survived\n", curr->num);
    
    return 0;
}