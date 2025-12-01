#include <stdio.h>
#include <stdlib.h>

struct listNode {
    char data;
    struct listNode *link;
};
typedef struct listNode* list_pointer;

list_pointer invert(list_pointer);
void print_list(list_pointer);

int main()
{
    list_pointer head, a, b, c, d, inverted;
    a = (list_pointer)malloc(sizeof(struct listNode));
    b = (list_pointer)malloc(sizeof(struct listNode));
    c = (list_pointer)malloc(sizeof(struct listNode));
    d = (list_pointer)malloc(sizeof(struct listNode));
    head = a;
    a->data = 'A';
    b->data = 'B';
    c->data = 'C';
    d->data = 'D';
    a->link = b;
    b->link = c;
    c->link = d;
    d->link = NULL;

    print_list(head);
    inverted = invert(head);
    print_list(inverted);

    return 0;
}

list_pointer invert(list_pointer lead){
    list_pointer middle, trail;
    middle = NULL;
    while (lead){
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    return middle;
}

void print_list(list_pointer lead){
    list_pointer temp = lead;
    while (temp){
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}