#include <stdio.h>
#include "linkedlist.h"

void print_item(link p)
{
	printf("%d\t", p->item);
}

int main(void)
{
	link p = make_node(8);
	insert(p);
	p = make_node(5);
	insert(p);
	p = make_node(3);
	insert(p);
	p = make_node(1);
	insert(p);
	traverse(print_item);
    printf("\n");

    insert_sort(1);
    traverse(print_item);
    printf("\n");
    insert_sort(4);
    traverse(print_item);
    printf("\n");
    insert_sort(10);
    traverse(print_item);
    printf("\n");
    return 0;
}