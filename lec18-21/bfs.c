#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct node {
    int vertex;
    struct node* link;
};

struct queue {
    int item;
    struct queue* link;
};

typedef struct node* nodePointer;
typedef struct queue* queue_pointer;
queue_pointer front, rear;

void addq(queue_pointer *front, queue_pointer *rear, int item);
int deleteq(queue_pointer *front);
void bfs(int v);

nodePointer graph[MAX_VERTICES];
int visited[MAX_VERTICES];

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
    
    bfs(0);
    printf("\n");

    return 0;
}

void addq(queue_pointer *front, queue_pointer *rear, int item) {
    queue_pointer temp = (queue_pointer)malloc(sizeof(struct queue));
    temp->item = item;
    temp->link = NULL;
    if (*front)
        (*rear)->link = temp;
    else (*front) = temp;
    (*rear) = temp;
}

int deleteq(queue_pointer *front) {
    queue_pointer temp = (*front);
    int item;
    if (*front == NULL) {
        fprintf(stderr, "The queue is empty");
        exit(1);
    } else {
        item = (*front)->item;
        (*front) = temp->link;
        free(temp);
    }
    return item;
}

void bfs(int v) {
    nodePointer w;
    visited[v] = 1;
    printf("%3d", v);
    addq(&front, &rear, v);
    while (front) {
        v = deleteq(&front);
        for (w = graph[v]; w; w = w->link) {
            if (!visited[w->vertex]) {
                printf("%3d", w->vertex);
                addq(&front, &rear, w->vertex);
                visited[w->vertex] = 1;
            }
        }
    }
}