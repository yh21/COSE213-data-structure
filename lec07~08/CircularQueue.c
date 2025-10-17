#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define INVALID_KEY -1

typedef struct{
    int key;
    /* anything need */
} element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;
int size = 0;

void addq(element);
element deleteq();
void queueFull();
element queueEmpty();

int main(){
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
    if (size == MAX_QUEUE_SIZE)
        queueFull();
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
    size++;
}

element deleteq(){
    if (size == 0)
        return queueEmpty();
    front = (front + 1) % MAX_QUEUE_SIZE;
    size--;
    return queue[front];
}

void queueFull(){
    if (front == -1){
        fprintf(stderr, "No more space in this queue");
        exit(1);
    }
}

element queueEmpty(){
    element e;
    e.key = INVALID_KEY;
    return e;
}