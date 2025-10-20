#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define INVALID_KEY -1

typedef struct{
    int key;
    /* anything else if need*/
} element;

element CQueue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(element);
void queueFull();
element dequeue();
element queueEmpty();

int main(){

  int i;
  element e;

  for(i = 0; i < 8; i++) {
    e.key = i;
    enqueue(e);
    printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
  }

  for(i = 0; i < 8; i++) {
    e = dequeue();
    printf("key %2d  deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
  }

  for(i = 8; i < 16; i++) {
    e.key = i;
    enqueue(e);
    printf("key %2d inserted into the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
  }

  for(i = 8; i < 16; i++) {
    e = dequeue();
    printf("key %2d  deleted from the queue. (front: %2d rear: %2d)\n", e.key, front, rear);
  }
    return 0;
}

void enqueue(element item){
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if (rear == front)
        queueFull();
    CQueue[rear] = item;
}

void queueFull(){
    fprintf(stderr, "queue is full");
    exit(1);
}

element dequeue(){
    if (front == rear)
        return queueEmpty();
    front = (front + 1) % MAX_QUEUE_SIZE;
    return CQueue[front];
}

element queueEmpty(){
    element e;
    e.key = INVALID_KEY;
    return e;
}