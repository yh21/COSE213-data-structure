#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
} element;
element heap[MAX_ELEMENTS];
int n = 0;

void insert_max_heap(element item, int *n);
element delete_max_heap(int *n);

int main() {

    int i, rn;
    element item;

    srand(time(NULL));
    
    printf("INSERTING: ");
    for(i=0; i<10; i++) {
        rn = rand() % 100 + 1;
        printf("%3d ", rn);
        item.key = rn;
        insert_max_heap(item, &n);
    }
    printf("\n\n");

    printf("DELETING:  ");
    for(i=0; i<10; i++) {
        item = delete_max_heap(&n);
        printf("%3d ", item.key);
    }
    printf("\n");

    return 0;
}

void insert_max_heap(element item, int *n) {
    if (HEAP_FULL(*n)) {
        fprintf(stderr, "The heap is full");
        exit(1);
    }
    int i = ++(*n);
    while (i != 1 && item.key > heap[i/2].key) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

element delete_max_heap(int *n) {
    int parent, child;
    element temp, item;

    if (HEAP_EMPTY(*n)) {
        fprintf(stderr, "The heap is empty");
        exit(1);
    }

    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;

    while (child <= *n) { // 비교할 자식 노드가 남아있는지 확인
        if (child < *n && (heap[child].key < heap[child + 1].key)) child++;
        if (temp.key >= heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}