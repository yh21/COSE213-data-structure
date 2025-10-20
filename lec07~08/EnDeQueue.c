#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define INVALID_KEY -1

typedef struct{
    int key;
    /* anything else if need*/
} element;

element queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(element);
void queueFull();
element dequeue();
element queueEmpty();

int main(){

    for (int i = 1; i < 15; i++){
        element e;
        e.key = i;
        enqueue(e);
        printf("enqueue : %d\n", e.key);
    }

    for (int i = 1 ; i < 8; i++){
        element e = dequeue();
        printf("dequeue : %d\n", e.key);
    }

    return 0;
}

void enqueue(element item){
    if (rear >= MAX_QUEUE_SIZE - 1)
        queueFull();
    queue[++rear] = item;
}

void queueFull(){
    fprintf(stderr, "the queue is full\n");
    exit(1);
}

element dequeue(){
    if (front == rear)
        return queueEmpty();
    return queue[++front];
}

element queueEmpty(){
    element e;
    e.key = INVALID_KEY;
    return e;
}