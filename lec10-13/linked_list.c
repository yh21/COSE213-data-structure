#include <stdio.h>
#include <stdlib.h>

struct listNode {
    char data;
    struct listNode* link;
};
struct listNode *first = NULL;

int main()
{
    struct listNode *newNode = NULL;
    struct listNode *prevNode = NULL;
    struct listNode *currNode = NULL;
    char c;

    // add element in linked list
    for (c = 'a'; c <= 'e'; c++){
        newNode = malloc(sizeof(*newNode));
        newNode->data = c;
        newNode->link = NULL;
        if (prevNode == NULL) first = newNode;
        else prevNode->link = newNode;
        prevNode = newNode;
    }

    // print all element in linked list
    currNode = first;
    while (currNode){
        printf("%c ", currNode->data);
        currNode = currNode->link;
    }
    printf("\n");

    // reading the third element
    currNode = first->link->link;
    printf("reading the third element: %c", currNode->data);
    printf("\n");

    // deleting the third element
    currNode = first->link->link;
    prevNode = first->link;
    prevNode->link = currNode->link;
    free(currNode);
    printf("deleting third node\n");

    // print all element in linked list
    currNode = first;
    while (currNode){
        printf("%c ", currNode->data);
        currNode = currNode->link;
    }
    printf("\n");

    // insert new data 'f' as the third node in the list
    newNode = malloc(sizeof(*newNode));
    newNode->data = 'f';
    newNode->link = NULL;
    prevNode = first->link;
    newNode->link = prevNode->link;
    prevNode->link = newNode;
    printf("inserting 'f' as the 3rd element\n");

    // insert new data 'g' as the first node in the list
    newNode = malloc(sizeof(*newNode));
    newNode->data = 'g';
    newNode->link = NULL;
    newNode->link = first;
    first = newNode;
    printf("inserting 'g' as the first element\n");

    // print all element in linked list
    currNode = first;
    while (currNode){
        printf("%c ", currNode->data);
        currNode = currNode->link;
    }
    printf("\n");

    return 0;
}