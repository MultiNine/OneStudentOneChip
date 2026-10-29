#include <stdio.h>
#include <assert.h>
#include "list_algos.h"

void ListNode_swap(ListNode *a, ListNode *b)
{
    void *temp = a->value;
    a->value = b->value;
    b->value = temp;
}

int List_bubble_sort(List *list, List_compare cmp)
{

    int sorted = 0;

    if(list == NULL || cmp == NULL) {
        return -1;
    }

    #ifndef NDEBUG
        assert(List_check(list));
    #endif

    if(list->count <= 1) {
        #ifndef NDEBUG
            assert(List_check(list));
        #endif
        return 0;
    }

    do {
        sorted = 1;
        LIST_FOREACH(list, first, next, cur) {
            if(cur->next) {
                if(cmp(cur->value, cur->next->value) > 0) {
                    ListNode_swap(cur, cur->next);
                    sorted = 0;
                }
            }
        }
    } while(!sorted);

    #ifndef NDEBUG
        assert(List_check(list)); 
        assert(List_is_sorted(list, cmp) == 1);
    #endif

    return 0;
}

int List_is_sorted(List *list, List_compare cmp)
{
    if(list == NULL || cmp == NULL) {
        return -1;
    }

    for(ListNode *cur = list->first;
        cur != NULL && cur->next != NULL;
        cur = cur->next) {
        if(cmp(cur->value, cur->next->value) > 0) {
            return 0;
        }
    }

    return 1;
}

ListNode *List_take_first_node(List *list)
{
    if(list == NULL || list->first == NULL) {
        return NULL;
    }

    ListNode *node = list->first;
    list->first = node->next;

    if(list->first != NULL) {       
        list->first->prev = NULL;
    } else {
        list->last = NULL;  // 取出节点后原链表变为空链表
    }

    list->count--;

    node->next = NULL;
    node->prev = NULL;

    return node;
}

void List_append_node(List *list, ListNode *node)
{
    if(list == NULL || node == NULL) {
        return;
    }

    assert(node->next == NULL);
    assert(node->prev == NULL);

    if(list->count == 0) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    list->count++;
}

List *List_merge(List *left, List *right, List_compare cmp)
{
    if(left == NULL || right == NULL || cmp == NULL || left == right) {
        return NULL;
    }

    List *result = List_create();
    if(result == NULL) {
        return NULL;
    }

    while(left->first != NULL && right->first != NULL) {
        if(cmp(left->first->value, right->first->value) > 0) {
            List_append_node(result, List_take_first_node(right));
        } else {
            List_append_node(result, List_take_first_node(left));
        }
    }

    List_concat(left, result);
    List_concat(right, result);

    return result;
}

List *List_merge_sort(List *list, List_compare cmp)
{
    if(list == NULL || cmp == NULL) {
        return NULL;
    }

    #ifndef NDEBUG
        assert(List_check(list));
    #endif

    // Already sorted!
    if(list->count <= 1 || List_is_sorted(list, cmp)) {
        #ifndef NDEBUG
            assert(List_check(list));
        #endif
        return list;
    }

    List *left = List_create();
        if(left == NULL) {
        return NULL;
    }
    List_concat(list, left);
    List *right = List_split(left, left->count / 2);
    if(right == NULL) {
        List_concat(left, list);
        List_destroy(left);
        return NULL;
    }


    List *sorted_left = List_merge_sort(left, cmp);
    if(sorted_left == NULL) {
        List_concat(left, list);
        List_concat(right, list);

        List_destroy(left);
        List_destroy(right);
        return NULL;
    }

    List *sorted_right = List_merge_sort(right, cmp);
    if(sorted_right == NULL) {
        List_concat(sorted_left, list);
        List_concat(right, list);

        if(sorted_left != left) List_destroy(left);
        List_destroy(sorted_left);
        List_destroy(right);
        return NULL;
    }

    List *result = List_merge(sorted_left, sorted_right, cmp);
    if(result == NULL) {
        List_concat(sorted_left, list);
        List_concat(sorted_right, list);

        if(sorted_left != left) List_destroy(left);
        if(sorted_right != right) List_destroy(right);
        List_destroy(sorted_left);
        List_destroy(sorted_right);
        return NULL;
    }

    // 排序成功，释放临时链表结构
    if(sorted_left != left) List_destroy(left);
    if(sorted_right != right) List_destroy(right);
    List_destroy(sorted_left);
    List_destroy(sorted_right);

    #ifndef NDEBUG
        assert(List_check(result));
        assert(List_is_sorted(result, cmp) == 1);
    #endif

    return result;
}

int List_insert_sorted(List *list, void *value, List_compare cmp)
{
    if(list == NULL || cmp == NULL) {
        return -1;
    }

    #ifndef NDEBUG
        assert(List_check(list));
        assert(List_is_sorted(list, cmp) == 1);
    #endif
    
    if(list->count == 0) {
        List_unshift(list, value);
    } else if(cmp(list->first->value, value) > 0) {
        List_unshift(list, value);
    } else if(cmp(list->last->value, value) <= 0) {
        List_push(list, value);
    } else {
        ListNode *cur = list->first;
        while(cur != NULL && cmp(cur->value, value) <= 0) {
            cur = cur->next;
        }
        ListNode *node = calloc(1, sizeof(ListNode));
        if(node == NULL) {
            return -1;
        }
        node->value = value;

        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        list->count++;
    }

    #ifndef NDEBUG
        assert(List_check(list));
        assert(List_is_sorted(list, cmp) == 1);
    #endif

    return 0;
}

ListNode *merge_nodes(ListNode *a, ListNode *b, List_compare cmp)
{
    ListNode *node = NULL;
    ListNode *head = NULL;  // 结果链表的头节点
    ListNode *tail = NULL;  // 结果链表的尾节点

    while(a != NULL && b != NULL) {
        if(cmp(a->value, b->value) <= 0) {
            node = a;
            a = a->next;
        } else {
            node = b;
            b = b->next;
        }

        node->next = NULL;

        if(head == NULL) {
            node->prev = NULL;
            head = node;
            tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    while(a != NULL) {
        node = a;
        a = a->next;
        node->next = NULL;
        if(head == NULL) {
            node->prev = NULL;
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    while(b != NULL) {
        node = b;
        b = b->next;
        node->next = NULL;
        
        if(head == NULL) {
            node->prev = NULL;
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}

int List_merge_sort_bottom_up(List *list, List_compare cmp)
{
    if(list == NULL || cmp == NULL) {
        return -1;
    }

    if(list->count <= 1) {
        return 0;
    }

    ListNode *bins[32] = {NULL};
    ListNode *cur = list->first;

    while(cur != NULL) {
        ListNode *next = cur->next;
        cur->prev = NULL;
        cur->next = NULL;

        ListNode *run = cur;
        int i = 0;

        while(i < 32 && bins[i] != NULL) {
            run = merge_nodes(bins[i], run, cmp);
            bins[i] = NULL;
            i++;
        }

        assert(i < 32);
        bins[i] = run;
        cur = next;
    }

    ListNode *result = NULL;
    for(int i = 0; i < 32; i++) {
        if(bins[i] != NULL) {
            result = merge_nodes(bins[i], result, cmp);
        }
    }

    list->first = result;

    ListNode *result_tail = result;
    while(result_tail->next != NULL) {
        result_tail = result_tail->next;
    }
    list->last = result_tail;

    return 0;

}