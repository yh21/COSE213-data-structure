#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define INVALID_KEY -1

typedef struct{
    int key;
    /* anything else need*/
} element;

element queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void addq(element);
element deleteq();
void queueFull();
element queueEmpty();


int main()
{
    element e;

    for (int i = 1; i <= 8; i++){
        e.key = i;
        addq(e);
        printf("key %2d is inserted in the queue, (front = %2d, rear = %2d)\n", e.key, front, rear);
    }

    for (int i = 1; i <= 8; i++){
        printf("key %2d is deleted in the queue, (front = %2d, rear = %2d)\n", deleteq().key, front, rear);
    }

    for (int i = 9; i <= 16; i++){
        e.key = i;
        addq(e);
        printf("key %2d is inserted in the queue, (front = %2d, rear = %2d)\n", e.key, front, rear);
    }

    for (int i = 9; i <= 16; i++){
        printf("key %2d is deleted in the queue, (front = %2d, rear = %2d)\n", deleteq().key, front, rear);
    }

    for (int i = 17; i <= 30; i++){
        e.key = i;
        addq(e);
        printf("key %2d is inserted in the queue, (front = %2d, rear = %2d)\n", e.key, front, rear);
    }
    
    return 0;
}

void addq(element item){
    if (rear == MAX_QUEUE_SIZE - 1)
        queueFull();
    queue[++rear] = item;
}

element deleteq(){
    if (front == rear)
        return queueEmpty();
    return queue[++front];
}

void queueFull(){
    int offset;
    offset = front + 1;

    if (front == -1){
        fprintf(stderr, "No more space in this queue!\n");
        exit(1);
    }

    for (int i = front + 1; i < MAX_QUEUE_SIZE; i++)
        queue[i - offset] = queue[i];
    
    front -= offset;
    rear -= offset;

    printf(" ==== queue reorganized. (front: %2d rear: %2d) ====\n", front, rear);
}

element queueEmpty(){
    element e;
    e.key = INVALID_KEY;
    return e;
}