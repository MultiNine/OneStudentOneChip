#include <stdio.h>

#define MAX_SIZE 3

int stack[MAX_SIZE];
int top = -1;

void push(int value)    // ÈëÕ»
{
    if(top == MAX_SIZE - 1) {         // Õ»Âú
        printf("Stack is full.\n");
    } else {
        top++;
        stack[top] = value;
        printf("top = %d, value = %d\n", top, value);
    }
}

int pop(void)                 // ³öÕ»
{
    if(top == -1) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        int n = stack[top];
        top--;
        printf("top = %d, value = %d\n", top, n);
        return n;
    }
}

int main(int argc, char *argv[])
{
    push(1);
    push(2);
    push(3);
    push(4);

    int a = pop();
    int b = pop();
    int c = pop();
    int d = pop();

    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

}


