#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(x) !x
#define IS_EMPTY(x) !x
#define MAX_QUEUES 10

typedef struct {
    int key;
} element;

struct queue {
    element item;
    struct queue *link;
};

typedef struct queue* queue_pointer;
queue_pointer front[MAX_QUEUES], rear[MAX_QUEUES];

void addq(queue_pointer *front, queue_pointer *rear, element item);
element deleteq(queue_pointer *front);
void printQueue(queue_pointer front);

int main()
{
    int i;
    for(i=0; i<10; i++) {
        element e;
        e.key = i+1;
        addq(&front[0], &rear[0], e);
        printQueue(front[0]);
    }

    for(i=0; i<10; i++) {
        element e;
        e = deleteq(&front[0]);
        printQueue(front[0]);
    }
}

void addq(queue_pointer* front, queue_pointer* rear, element item){
    queue_pointer temp = (queue_pointer)malloc(sizeof(struct queue));
    if (IS_FULL(temp)){
        fprintf(stderr, "The memory is full");
        exit(1);
    }
    temp->item = item;
    temp->link = NULL;
    if (*front){
        (*rear)->link = temp;
    }
    else {
        (*front) = temp;
    }
    (*rear) = temp;
}

element deleteq(queue_pointer *front){
    if (IS_EMPTY(*front)){
        fprintf(stderr, "The queue is empty");
        exit(1);
    }
    queue_pointer temp = (*front);
    element item = temp->item;
    *front = temp->link;
    free(temp);
    return item;
}

void printQueue(queue_pointer front){
    
    while (front){
        printf("%3d", front->item.key);
        front = front->link;
    }
    printf("\n");
}