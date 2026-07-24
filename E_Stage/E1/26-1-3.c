#include <stdio.h>
#include "linkedlist.h"

void print_item(link p)
{
	printf("%d\t", p->item);
}

int main(void)
{
	link p = make_node(4);
	insert(p);
	p = make_node(3);
	insert(p);
	p = make_node(2);
	insert(p);
	p = make_node(1);
	insert(p);
	traverse(print_item);
    printf("\n");

    reverse();
    traverse(print_item);
    printf("\n");
    return 0;
}