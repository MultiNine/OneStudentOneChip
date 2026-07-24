/* linkedlist.c */
#include <stdlib.h>
#include "linkedlist.h"

static link head = NULL;
static link tail = NULL;

link make_node(unsigned char item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->next = NULL;
	return p;
}

void free_node(link p)
{
	free(p);
}

link search(unsigned char key)
{
	link p;
	for (p = head; p; p = p->next) // p != NULL 时循环
		if (p->item == key)
			return p;
	return NULL;
}

void insert(link p)    // 在链表头部插入节点
{
	p->next = head;
	head = p;
}

void delete(link p)
{
	link pre;
	if (p == head) {
		head = p->next;
		return;
	}
	for (pre = head; pre; pre = pre->next)
		if (pre->next == p) {
			pre->next = p->next;
			return;
		}
}

void traverse(void (*visit)(link))    // 遍历链表
{
	link p;
	for (p = head; p; p = p->next)
		visit(p);
}

void destroy(void)
{
	link q, p = head;
	head = NULL;
	while (p) {
		q = p;
		p = p->next;
		free_node(q);
	}
}

void push(link p)
{
	insert(p);
}

link pop(void)
{
	if (head == NULL)
		return NULL;
	else {
		link p = head;
		head = head->next;
		return p;
	}
}

void insert_sort(unsigned char c)
{
    link p;                 // 遍历指针
    link new = make_node(c);

    /* 插入前链表为空 */
    if (head == NULL) {
        head = new;
        return;
    }
        
    /* 插入数据比第一个数还小 在头部插入 */
    if (new->item <= head->item) {
        new->next = head;
        head = new;
        return;
    }
    else {
        for (p = head; p; p = p->next) {
            if (p->next == NULL) {                      // 在末尾插入
                new->next = NULL;
                p->next = new;
                return;
            }    

            if (p->item <= c && p->next->item >= c) {   // 找到要插入的位置
                new->next = p->next;
                p->next = new;
                return;
            }
        }
    }
}

void enqueue(link p)
{
    /* 初始链表为空 */
    if (head == NULL && tail == NULL) {
        head = p;
        tail = p;
    }
    else {
        tail->next = p;
        tail = p;
    }
    return;
}

link dequeue(void)
{
    link p = head;
    head = head->next;

    /* 取出节点为最后一个节点 */
    if (head == NULL)
        tail = NULL;
    
    p->next = NULL;
    return p;
}

void reverse(void)
{
    link prev, curr, next;
    prev = NULL;
    curr = head;
    
    /* NULL a -> b -> c -> d NULL 
        ↑   ↑    ↑                
      prev curr next              */
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        
        /* 移向下一个节点 */
        prev = curr;
        curr = next;
    }

    head = prev;    // 最后需要指定头节点
}