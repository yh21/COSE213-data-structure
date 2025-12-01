#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define COMPARE(x, y) (x < y ? -1: (x > y ? 1 : 0))
#define IS_FULL(x) !x

struct polyNode {
    float coef;
    int expon;
    struct polyNode* link;
};
typedef struct polyNode* poly_pointer;
poly_pointer avail = NULL;

poly_pointer get_node();
void ret_node(poly_pointer);
void cerase(poly_pointer*);
poly_pointer cpadd(poly_pointer, poly_pointer);
void attach(float, int, poly_pointer*);
void print_polynomial(poly_pointer);

int main()
{
    poly_pointer a, a_rear, b, b_rear, d;
    a = get_node();
    a->expon = -1;
    a->link = a;
    a_rear = a;
    attach(3, 14, &a_rear);
    attach(2, 8, &a_rear);
    attach(1, 0, &a_rear);

    b = get_node();
    b->expon = -1;
    b->link = b;
    b_rear = b;
    attach(8, 14, &b_rear);
    attach(-3, 10, &b_rear);
    attach(10, 6, &b_rear); 

    print_polynomial(a);
    print_polynomial(b);
    d = cpadd(a, b);
    print_polynomial(d);

    cerase(&a);
    cerase(&b);
    cerase(&d);

    return 0;
}

poly_pointer get_node(){
    poly_pointer node;
    if (avail){
        node = avail;
        avail = avail->link;
    }
    else {
        node = (poly_pointer)malloc(sizeof(struct polyNode));
        if (IS_FULL(node)){
            fprintf(stderr, "The memory is FULL");
            exit(1);
        }
    }
    return node;
}

void ret_node(poly_pointer ptr){
    ptr->link = avail;
    avail = ptr;
}

void print_polynomial(poly_pointer a){
    poly_pointer temp = a->link;
    if (temp != a){
        printf("%.1fx^%d ", temp->coef, temp->expon);
        temp = temp->link;
    }
    while (temp != a){
        if (temp->coef < 0) printf("%.1fx^%d ", temp->coef, temp->expon);
        else printf("+%.1fx^%d ", temp->coef, temp->expon);
        temp = temp->link;
    }
}

poly_pointer cpadd(poly_pointer a, poly_pointer b){
    poly_pointer starta, d, lastd;
    int sum;
    int done = FALSE;
    
    starta = a;
    a = a->link;
    b = b->link;
    d = get_node();
    d->expon = -1;
    lastd = d;

    do {
        switch (COMPARE(a->expon, b->expon)){
            case -1:
                attach(b->coef, b->expon, &lastd);
                b = b->link;
                break;
            case 0:
                if (starta == a) done = TRUE;
                else {
                    sum = a->coef + b->coef;
                    if (sum){
                        attach(sum, a->expon, &lastd);
                        a = a->link;
                        b = b->link;
                    }
                }
            case 1:
                attach(a->coef, a->expon, &lastd);
                a = a->link;
        }   
    } while (!done);
    lastd->link = d;
    return d;
}

void attach(float coefficient, int exponent, poly_pointer* ptr){
    poly_pointer temp;
    temp = (poly_pointer)malloc(sizeof(struct polyNode));
    if (IS_FULL(temp)){
        fprintf(stderr, "The memory is full");
        exit(1);
    }
    temp->coef = coefficient;
    temp->expon = exponent;
    temp->link = (*ptr)->link;
    (*ptr)->link = temp;
    (*ptr) = temp; // more
}

void cerase(poly_pointer* ptr){
    poly_pointer temp;
    if (*ptr){
        temp = (*ptr)->link;
        (*ptr)->link = avail;
        avail = temp;
        (*ptr) = NULL;
    }
}