#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

struct node {
  char data;
  struct node *left_child, *right_child;
};
typedef struct node *tree_pointer;

tree_pointer create_tree_node(char data);
void recursive_inorder(tree_pointer ptr);
void iter_inorder(tree_pointer ptr);
void iter_postorder(tree_pointer ptr);
void iter_preorder(tree_pointer ptr);
void level_order(tree_pointer ptr);

/* TODO: add function prototype if necessary */
void addq(int, int *, tree_pointer);
tree_pointer deleteq(int *, int);
tree_pointer queue[MAX_QUEUE_SIZE];

void main() {

  /* create a tree that represents an arithmetic expression */
  tree_pointer ptr, ptr1, ptr2;

  ptr1 = create_tree_node('A');
  ptr2 = create_tree_node('B');
  ptr = create_tree_node('/');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  ptr1 = ptr;
  ptr2 = create_tree_node('C');
  ptr = create_tree_node('*');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  ptr1 = ptr;
  ptr2 = create_tree_node('D');
  ptr = create_tree_node('*');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  ptr1 = ptr;
  ptr2 = create_tree_node('E');
  ptr = create_tree_node('+');
  ptr->left_child = ptr1;
  ptr->right_child = ptr2;

  /* call traversal functions */
  recursive_inorder(ptr);
  printf("\n");
  iter_inorder(ptr);
  printf("\n");
  iter_preorder(ptr);
  printf("\n");
  iter_postorder(ptr);
  printf("\n");
  level_order(ptr);
  printf("\n");
}
  
tree_pointer create_tree_node(char data) {
  tree_pointer ptr = (tree_pointer)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->left_child = NULL;
  ptr->right_child = NULL;
  return ptr;
}

void recursive_inorder(tree_pointer ptr) {
  if(ptr) {
    recursive_inorder(ptr->left_child);
    printf("%c ", ptr->data);
    recursive_inorder(ptr->right_child);
  }
}

void iter_inorder(tree_pointer ptr) { 
  int top = -1;
  tree_pointer stack[MAX_STACK_SIZE];
  for( ; ; ) {
    for( ; ptr; ptr = ptr->left_child)
      stack[++top] = ptr;
    if(top < 0) break;
    ptr = stack[top--];
    printf("%c ", ptr->data);
    ptr = ptr->right_child;
  }
}

void iter_preorder(tree_pointer ptr) {
    /* TODO: you must complete this function */
    int top = -1;
    tree_pointer stack[MAX_STACK_SIZE];
    if (ptr) stack[++top] = ptr;
    while (top > -1){
        ptr = stack[top--];
        printf("%c ", ptr->data);
        if (ptr->right_child)
            stack[++top] = ptr->right_child;
        if (ptr->left_child)
            stack[++top] = ptr->left_child;
    }
}
void iter_postorder(tree_pointer ptr) {
    /* TODO: you must complete this function */
    int top1 = -1;
    int top2 = -1;
    tree_pointer stack1[MAX_STACK_SIZE];
    tree_pointer stack2[MAX_STACK_SIZE];
    
    if (!ptr) return;

    stack1[++top1] = ptr;
    while (top1 > -1) {
        ptr = stack1[top1--]; 
        stack2[++top2] = ptr;
        if (ptr->left_child)  stack1[++top1] = ptr->left_child;
        if (ptr->right_child) stack1[++top1] = ptr->right_child;
    }

    while (top2 > -1) {
        printf("%c ", stack2[top2--]->data);
    }
}

void level_order(tree_pointer ptr) {
    /* TODO: you must complete this function */
    int front = 0;
    int rear = 0;
    if (!ptr) return;
    addq(front, &rear, ptr);
    for (; ;){
        ptr = deleteq(&front, rear);
        if(ptr){
            printf("%c ", ptr->data);
            if (ptr->left_child) addq(front, &rear, ptr->left_child);
            if (ptr->right_child) addq(front, &rear, ptr->right_child);
        }
        else break;
    }
}

/* TODO: add function implementations here */
void addq(int front, int *rear, tree_pointer ptr) {
    if (*rear == MAX_QUEUE_SIZE - 1) {
        printf("Error: Queue is full.\n");
        return;
    }
    *rear = *rear + 1;
    queue[*rear] = ptr;
}

tree_pointer deleteq(int *front, int rear) {
    if (*front == rear) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }
    *front = *front + 1;
    return queue[*front];
}