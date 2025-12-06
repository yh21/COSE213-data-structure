/* 시험에 나온다고 합니다 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element;

struct node {
    element item;
    struct node* llink;
    struct node* rlink;
};
typedef struct node* node_pointer;

void dinsert(node_pointer, node_pointer);
void ddelete(node_pointer, node_pointer);
void dprint(node_pointer);
void dprintreverse(node_pointer);

int main()
{
    node_pointer head, curr, newnode, delnode;
    int i;
    
    head = (node_pointer)malloc(sizeof(struct node));
    head->item.key = -1;
    head->rlink = head;
    head->llink = head;

    curr = head;
    for(i=0; i<10; i++) {
        newnode = (node_pointer)malloc(sizeof(struct node));
        newnode->item.key = i+1;
        newnode->rlink = NULL;
        newnode->llink = NULL;
        dinsert(curr, newnode);
        curr = newnode;  
        dprint(head);
    }

    curr = head->rlink;
    while(curr != head) {
        delnode = curr;
        curr = curr->rlink;
        ddelete(head, delnode);
        dprintreverse(head);
    }
}

void dinsert(node_pointer node, node_pointer newnode){
    newnode->rlink = node->rlink;
    newnode->llink = node;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

void ddelete(node_pointer node, node_pointer delnode){
    if (node == delnode){
        printf("Deletion of head node is not permitted");
    }
    else { 
        delnode->llink->rlink = delnode->rlink;
        delnode->rlink->llink = delnode->llink;
        free(delnode);
    }
}

void dprint(node_pointer head){
    node_pointer temp = head->rlink;
    while (temp != head){
        printf("%3d", temp->item.key);
        temp = temp->rlink;
    }
    printf("\n");
}

void dprintreverse(node_pointer head){
    node_pointer temp = head->llink;
    while (temp != head){
        printf("%3d", temp->item.key);
        temp = temp->llink;
    }
    printf("\n");
}