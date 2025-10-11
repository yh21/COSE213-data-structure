#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_ROW 13
#define MAX_COL 17
#define EXIT_ROW 11
#define EXIT_COL 15
#define TRUE 1
#define FALSE 0

int maze[MAX_ROW][MAX_COL];
int mark[MAX_ROW][MAX_COL];

typedef struct {
    int row;
    int col;
    int dir;
} element;
element stack[MAX_STACK_SIZE];
int top;

typedef struct{
    int vert;
    int horiz;
} offsets;
offsets move[8];

void push(element);
element pop();
void stackFull();
element stackEmpty();
void path();

int main(){

    /* initialize maze */
    int maze_values[MAX_ROW][MAX_COL] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                          { 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
                                          { 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
                                          { 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
                                          { 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1 },
                                          { 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                                          { 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
                                          { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                          { 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
                                          { 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
                                          { 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
                                          { 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
                                          { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
    memcpy(maze, maze_values, sizeof(int) * MAX_ROW * MAX_COL);
    
    /* initialize mark */
    for (int i = 0; i < MAX_ROW; i++){
        for (int j = 0; j < MAX_COL; j++)
            mark[i][j] = 0;
    }

    /* initialize move */
    move[0].vert = -1; move[0].horiz =  0;    // N
    move[1].vert = -1; move[1].horiz =  1;    // NE
    move[2].vert =  0; move[2].horiz =  1;    // E
    move[3].vert =  1; move[3].horiz =  1;    // SE
    move[4].vert =  1; move[4].horiz =  0;    // S
    move[5].vert =  1; move[5].horiz = -1;    // SW
    move[6].vert =  0; move[6].horiz = -1;    // W
    move[7].vert = -1; move[7].horiz = -1;    // NW

    /* path function */
    path();

    return 0;
}

void push(element item){
    if(top >= MAX_STACK_SIZE - 1)
        stackFull();
    stack[++top] = item;
}

element pop(){
    if(top == -1)
        stackEmpty();
    return stack[top--];
}

void stackFull(){
    fprintf(stderr, "stack is full, cannot add element");
    exit(EXIT_FAILURE);
}

element stackEmpty(){
    element e;
    e.col = -1; e.row = -1; e.dir = -1;
    return e;
}

void path(){
    int i, row, col, nextRow, nextCol, dir, found = FALSE;
    element position;
    mark[1][1] = 1, top = 0; // [1][1]에 방문했음
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;

    while (top > -1 && !found){
        position = pop(); // position = stack 가장 위의 element
        row = position.row; col = position.col; dir = position.dir;
        while (dir < 8 && !found){ // 더 찾을 수 없거나 !found일 때까지
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
                found = TRUE;
            else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]){ // 가는 곳이 벽이 아님 && 가본 적이 없음
                mark[nextRow][nextCol] = 1;
                position.row = row; position.col = col;
                position.dir  = ++dir;
                push(position);
                row = nextRow; col = nextCol; dir = 0;
            }
            else // 가는 곳이 벽이거나 가본 적 있음
                ++dir;
        }
    }
    if(found){
        printf("The path is: \n");
        printf("row col\n");
        for(i = 0; i <= top; i++) 
            printf("%2d%5d\n", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else
        printf("The maze doesn't have path");
}