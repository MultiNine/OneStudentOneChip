#include <lcthw/list.h>
#include <lcthw/dbg.h>
#include <assert.h>


int List_check(List *list)
{
    if(list == NULL || list->count < 0) {
        return 0;
    }

    if(list->count == 0) {
        return list->first == NULL && list->last == NULL;
    }

    if(list->first == NULL || list->last == NULL) {
        return 0;
    }

    if(list->first->prev != NULL || list->last->next != NULL) {
        return 0;
    }

    int cnt = 0;
    ListNode *prev = NULL;
    ListNode *cur = list->first;
    while(cur != NULL && cnt < list->count) {
        if(cur->prev != prev) {
            return 0;
        }
        prev = cur;
        cur = cur->next;
        cnt++;
    }
    if(cnt != list->count || cur != NULL || prev != list->last) {
        return 0;
    }

    return 1;
}

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    assert(list != NULL);
    LIST_FOREACH(list, first, next, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void List_clear(List *list)
{
    assert(list != NULL);
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
    }
}


void List_clear_destroy(List *list)
{
    assert(list != NULL);
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
        if (cur->prev) {
            free(cur->prev);
        }
    }
    free(list->last);
    free(list);
}


void List_push(List *list, void *value)
{
    assert(list != NULL);
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;

error:
    return;
}

void *List_pop(List *list)
{
    assert(list != NULL);
    ListNode *node = list->last;
    return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List *list, void *value)
{
    assert(list != NULL);
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

void *List_shift(List *list)
{
    assert(list != NULL);
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node)
{
    assert(list != NULL);
    void *result = NULL;

    check(list->first && list->last, "List is empty.");
    check(node, "node can't be NULL");

    if(node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) {
        list->first = node->next;
        check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
        list->last->next = NULL;
    } else {
        ListNode *after = node->next;
        ListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->value;
    free(node);

error:
    return result;
}

List *List_copy(List *list)
{
    assert(list != NULL);

    List *copy = List_create();
        if(copy == NULL) {
            return NULL;
    }

    LIST_FOREACH(list, first, next, cur) {
        List_push(copy, cur->value);
    }

    return copy;
}

void List_concat(List *src, List *dest)
{
    assert(dest != NULL && src != NULL);
    assert(dest != src);

    if(src->count == 0) {
        return;
    } 
    
    if(dest->count == 0) {
        dest->first = src->first;
        dest->last = src->last;
    } else {
        dest->last->next = src->first;
        src->first->prev = dest->last;
        dest->last = src->last;
    }

    dest->count += src->count;

    src->first = NULL;
    src->last = NULL;
    src->count = 0;
}

List *List_split(List *list, int position)
{
    assert(list != NULL);
    assert(position >= 0 && position <= list->count);

    List *right = List_create();
    if(right == NULL) {
        return NULL;
    }
    int index = 0;

    if(position == 0) {
        right->first = list->first;
        right->last = list->last;
        right->count = list->count;

        list->first = NULL;
        list->last = NULL;
        list->count = 0;

        return right;
    } 
    
    if(position == list->count) {
        return right;
    } 
    
    LIST_FOREACH(list, first, next, cur) {
        if(index == position) {
            right->first = cur;
            right->last = list->last;
            list->last = cur->prev;
            cur->prev = NULL;
            list->last->next = NULL;
            right->count = list->count - position;
            list->count = position;
            return right;
        } else {
            index++;
        }
    }

    List_destroy(right);
    return NULL;
}
    
