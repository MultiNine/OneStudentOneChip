#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; };    
struct point path[512];           // 保存当前递归路径
int path_len = 0;                 // 当前路径长度

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_path(void)
{
	int i;
	for (i = 0; i < path_len; i++) {
        printf("(%d, %d)\n", path[i].row, path[i].col);
	}
}

int dfs(int row, int col)
{
    // 判断是否越界
    if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
        return 0;

    // maze[row][col] == 1 表示墙
    // maze[row][col] == 2 表示已经访问过
    if (maze[row][col] != 0)
        return 0;

    // 当前点合法，把它加入当前路径
    path[path_len].row = row;
    path[path_len].col = col;
    path_len = path_len + 1;

    // 标记当前点已经访问
    maze[row][col] = 2;

    // 判断是否到达终点
    if (row == MAX_ROW - 1 && col == MAX_COL - 1) {
        print_path();
        return 1;
    }
    
    // 递归尝试四个方向 右、下、左、上
    if (dfs(row, col + 1) == 1) {
        return 1;
    }
    if (dfs(row + 1, col) == 1) {
        return 1;
    }       
    if (dfs(row, col - 1) == 1) {
        return 1;
    }
    if (dfs(row - 1, col) == 1) {
        return 1;
    }

    // 四个方向都走不通，说明当前点不在最终路径上
    path_len = path_len - 1;

    return 0;
}

int main(void)
{
    if (dfs(0, 0) == 1)
        return 0;
    else
        printf("No path!\n");
	return 0;
}