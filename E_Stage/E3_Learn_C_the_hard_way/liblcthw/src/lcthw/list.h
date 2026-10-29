#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

/**
 * @brief 双向链表节点
 *
 * 每个节点保存一个数据指针，并通过next和prev
 * 分别连接后继节点和前驱节点。
 */
typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

/**
 * @brief 双向链表结构体
 *
 * 每个双向链表包含一个ListNode类型的指针first
 * 指向链表头节点、一个ListNode类型的指针lasr
 * 指向链表尾节点以及一个int类型的count保存链表的节点个数
 */
typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

/**
 * @brief 检查目标链表是否满足不变量
 *
 * @param list 要检查的链表指针
 * 
 * @return 检查通过后返回0
 */
int List_check(List *list);

/**
 * @brief 创建一个双向链表
 *
 */
List *List_create();

/**
 * @brief 销毁链表，释放所有节点和链表结构
 *
 * @param list 要摧毁的链表指针
 * 
 * @return 创建成功返回新链表指针，分配失败返回NULL
 * 
 * @note 不释放节点中value指向的数据
 */
void List_destroy(List *list);

/**
 * @brief 清空链表中每个节点的值
 *
 * @param list 要清空的链表指针
 *
 * @note 只释放各个节点的value，没有删除节点
 * @warning 释放后value成为悬空指针，不应再次访问或释放
 */
void List_clear(List *list);

/**
 * @brief 清理并销毁链表
 *
 * @param list 要清理并销毁的链表指针
 *
 * @note 相当于先调用List_clear()再调用List_destroy()
 */
void List_clear_destroy(List *list);

/**
 * @brief 获取链表中的节点数量
 * @param A 目标链表指针
 * @return 链表中的节点数量
 */
#define List_count(A) ((A)->count)

/**
 * @brief 获取链表的头节点
 * @param A 目标链表指针
 * @return 头节点保存的数据指针
 */
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)

/**
 * @brief 获取链表的尾节点
 * @param A 目标链表指针
 * @return 尾节点保存的数据指针
 */
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

/**
 * @brief 向链表尾添加新的元素
 *
 * @param list 要添加元素的链表指针
 * @param value 要添加的元素值
 */
void List_push(List *list, void *value);

/**
 * @brief 去除链表尾的最后一个元素
 *
 * @param list 要去除最后一个元素的链表指针
 * 
 * @return 去除元素的值，链表为空时返回NULL
 */
void *List_pop(List *list);

/**
 * @brief 向链表头添加新的元素
 *
 * @param list 要添加元素的链表指针
 * @param value 要添加的元素值
 */
void List_unshift(List *list, void *value);

/**
 * @brief 去除链表头部的第一个元素
 *
 * @param list 要去除头部第一个一个元素的链表指针
 * 
 * @return 去除元素的值，链表为空时返回NULL
 */
void *List_shift(List *list);

/**
 * @brief 去除链表中的一个节点
 *
 * @param list 要执行移除操作的链表指针
 * @param node 要移除的节点指针
 *
 * @note 执行List_pop或List_shift时，它执行实际的移除操作
 */
void *List_remove(List *list, ListNode *node);

/**
 * @brief 复制链表
 *
 * @param list 要进行复制的链表指针
 * 
 * @return 复制得到的链表指针
 */
List *List_copy(List *list);

/**
 * @brief 将src的所有节点连接到dest尾部
 * 
 * @param dest 目标链表
 * @param src 来源链表
 * 
 * @note 连接后src变为空链表，但src本身不会被释放
 */
void List_concat(List *src, List *dest);

/**
 * @brief 分割链表
 *
 * @param list 要分割的链表指针
 * 
 * @return 分割后的后半部分链表指针
 * 
 * @note 分割后list保留前position个节点，返回剩下的节点组成的链表指针
 */
List *List_split(List *list, int position);

/**
 * @brief 按指定方向遍历双向链表
 *
 * @param L 要遍历的链表指针
 * @param S 起始节点成员，first或last
 * @param M 移动方向成员，next或prev
 * @param V 当前节点变量名
 * 
 * @return 被删除节点保存的数据指针，操作失败返回NULL
 * 
 * @note 只释放节点本身，不释放节点保存的数据
 */
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif