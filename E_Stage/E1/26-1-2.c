#include <stdio.h>
#include "linkedlist.h"

void print_item(link p)
{
	printf("%d\t", p->item);
}

int main(void)
{
    link p;

    enqueue(make_node(1));
    traverse(print_item);
    printf("\n");
    enqueue(make_node(2));
    traverse(print_item);
    printf("\n");
    enqueue(make_node(3));
    traverse(print_item);
    printf("\n");

    dequeue();
    traverse(print_item);
    printf("\n");
    dequeue();
    traverse(print_item);
    printf("\n");
    dequeue();
    traverse(print_item);
    printf("\n");

    return 0;
}
