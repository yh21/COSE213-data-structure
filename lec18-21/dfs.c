#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct node {
    int vertex;
    struct node* link;
};

struct stack {
    int item;
    struct stack* link;
};

typedef struct node* nodePointer;
typedef struct stack* stackPointer;
stackPointer top;
nodePointer graph[MAX_VERTICES];
int visited[MAX_VERTICES];

void push(stackPointer*, int);
int pop(stackPointer*);
void printStack(stackPointer);
void dfs(int);
void dfs_iterative(int);

int main() {

    nodePointer prev;
    nodePointer np;

    /* adjacency list for vertex 0 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 1; np->link = NULL; graph[0] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 2; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 1 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 0; np->link = NULL; graph[1] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 3; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 4; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 2 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 0; np->link = NULL; graph[2] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 5; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 6; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 3 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 1; np->link = NULL; graph[3] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 4 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 1; np->link = NULL; graph[4] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 5 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 2; np->link = NULL; graph[5] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 6 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 2; np->link = NULL; graph[6] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 7; np->link = NULL; prev->link = np;

    /* adjacency list for vertex 7 */
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 3; np->link = NULL; graph[7] = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 4; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 5; np->link = NULL; prev->link = np; prev = np;
    np = (nodePointer)malloc(sizeof(struct node)); np->vertex = 6; np->link = NULL; prev->link = np;

    for(int i=0; i<8; i++) visited[i] = 0;
    
    dfs_iterative(0);
    printf("\n");

    return 0;
}

void printStack(stackPointer top) {
    stackPointer temp = top;
    while (temp != NULL) {
        printf("%3d", temp->item);
        temp = temp->link;
    }
}

int pop(stackPointer* top) {
    stackPointer temp = *top;
    int item;
    if (*top == NULL) {
        fprintf(stderr, "The stack is empty");
        exit(1);
    }
    item = temp->item;
    (*top) = temp->link;
    free(temp);
    return item;
}

void push(stackPointer *top, int item) {
    stackPointer temp = (stackPointer)malloc(sizeof(struct stack));
    temp->item = item;
    temp->link = (*top);
    *top = temp;
}

void dfs(int v) {
    nodePointer w;
    visited[v] = 1;
    printf("%3d", v);
    for (w = graph[v]; w; w = w->link) {
        if (!visited[w->vertex]) dfs(w->vertex);
    }
}

void dfs_iterative(int v) {
    nodePointer w;
    int u;
    push(&top, v);

    while (top) {
        u = pop(&top);
        if (!visited[u]) {
            printf("%3d", u);
            visited[u] = 1;
        }
        for (w = graph[u]; w; w = w->link) {
            if (!visited[w->vertex])
                push(&top, w->vertex);
        }
    }
}