#ifndef LIST_ALGOS_H
#define LIST_ALGOS_H
#include "list.h"

typedef int (*List_compare)(const void *a, const void *b);

int List_check(List *list);

void ListNode_swap(ListNode *a, ListNode *b);
int List_bubble_sort(List *list, List_compare cmp);

int List_is_sorted(List *list, List_compare cmp);
ListNode *List_take_first_node(List *list);
void List_append_node(List *list, ListNode *node);
List *List_merge(List *left, List *right, List_compare cmp);
List *List_merge_sort(List *list, List_compare cmp);

int List_insert_sorted(List *list, void *value, List_compare cmp);

ListNode *merge_nodes(ListNode *a, ListNode *b, List_compare cmp);
int List_merge_sort_bottom_up(List *list, List_compare cmp);

#endif