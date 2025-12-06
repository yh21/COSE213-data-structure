#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
typedef enum {entry, head} tagfield;

struct entry_node {
    int row;
    int col;
    int value;
};

struct matrix_node {
    struct matrix_node* down;
    struct matrix_node* right;
    tagfield tag;
    union {
        struct matrix_node* next;
        struct entry_node entry;
    } u;
};

typedef struct matrix_node *matrix_pointer;
matrix_pointer hdnode[MAX_SIZE];

matrix_pointer new_node();
matrix_pointer mread();
void mwrite(matrix_pointer node);
void merase(matrix_pointer *node);

int main()
{
    matrix_pointer m = mread();
    mwrite(m); 
    merase(&m);

    return 0;
}

matrix_pointer new_node(){
    matrix_pointer n = (matrix_pointer)malloc(sizeof(struct matrix_node));
    return n;
}


