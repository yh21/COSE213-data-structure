#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(x) !x

struct listNode {
    char data;
    struct listNode *link;
};
typedef struct listNode* list_pointer;

void print_circular_list(list_pointer);
void insert_front(list_pointer*, list_pointer);

int main()
{
    list_pointer a, b, c, d, last;
    a = (list_pointer)malloc(sizeof(struct listNode));
    b = (list_pointer)malloc(sizeof(struct listNode));
    c = (list_pointer)malloc(sizeof(struct listNode));
    a->data = 'a';
    b->data = 'b';
    c->data = 'c';
    a->link = b;
    b->link = c;
    c->link = a;
    last = c;
    print_circular_list(last);

    d = (list_pointer)malloc(sizeof(struct listNode));
    d->data = 'd';
    d->link = NULL;
    insert_front(&last, d);
    print_circular_list(last);

    return 0;
}

void print_circular_list(list_pointer last){
    list_pointer temp = last->link;
    while (1){
        printf("%c ", temp->data);
        if (temp == last) break;
        temp = temp->link;
    }
    printf("\n");
}

void insert_front(list_pointer* ptr, list_pointer node){
    if (IS_EMPTY(*ptr)) {
        (*ptr) = node;
        node->link = node;
    }
    else {
        node->link = (*ptr)->link;
        (*ptr)->link = node;
    }
}