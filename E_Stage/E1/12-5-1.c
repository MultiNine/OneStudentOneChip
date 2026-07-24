#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define QUEUE_SIZE 5

/* 不需要打印路径，删去predecessor */
struct point { int row, col; } queue[QUEUE_SIZE];
int head = 0, tail = 0;
int queue_error = 0;   /* 记录队列空间是否不够的全局变量 */

int is_empty(void)
{
	return head == tail;
}

int is_full(void)
{
    return (tail + 1) % QUEUE_SIZE == head;
}

void enqueue(struct point p)
{
    if (is_full()) {
        printf("queue is full!\n");
        queue_error = 1;   /* 队列空间不够 */
        return;
    }

	queue[tail] = p;
    tail = (tail + 1) % QUEUE_SIZE;
}

struct point dequeue(void)
{
	struct point p = queue[head];
    head = (head + 1) % QUEUE_SIZE;
    return p;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void visit(int row, int col)
{
	struct point visit_point = { row, col };

    if (is_full()) {       /* 如果队列满，就不先标记maze */
        enqueue(visit_point);
        return;
    }

	maze[row][col] = 2;
	enqueue(visit_point);
}

int main(void)
{
	struct point p = { 0, 0 };

	maze[p.row][p.col] = 2;
	enqueue(p);
	
	while (!is_empty() && !queue_error) {
		p = dequeue();
		if (p.row == MAX_ROW - 1  /* goal */
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     /* right */
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1);
		if (p.row+1 < MAX_ROW     /* down */
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col);
		if (p.col-1 >= 0          /* left */
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1);
		if (p.row-1 >= 0          /* up */
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col);
	}

    if (queue_error) {
        printf("队列空间不够，搜索结果无效\n");
    } else if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("有路能到终点\n");
	} else
		printf("No path!\n");

	return 0;
}