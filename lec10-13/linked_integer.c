#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int data;
    struct listNode *link;
};
struct listNode *head;

int find(int);
void printList();
int length();

int main()
{
    struct listNode *node = NULL;
    struct listNode *prevNode = NULL;

    for (int i = 10; i <= 100; i += 10){
        node = malloc(sizeof(*node));
        node->data = i;
        node->link = NULL;
        if (prevNode == NULL) head = node;
        else prevNode->link = node;
        prevNode = node;
    }

    printList();
    printf("result of finding %d: %d\n", 30, find(30));
    printf("number of integers in the list: %d\n", length());

    return 0;
}

void printList(){
    struct listNode *curr = head;
    printf("printList: ");
    while (curr){
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n");
}

int length(){
    int i = 0;
    struct listNode *curr = head;
    while (curr){
        i += 1;
        curr = curr->link;
    }
    return i;
}

int find(int n){
    int i = 0;
    struct listNode *curr = head;
    while (curr->data != n){
        i += 1;
        curr = curr->link;
    }
    return i;
}