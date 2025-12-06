#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1

struct node {
    int data;
    struct node* link;
};
typedef struct node* node_pointer;

int main()
{
    short int out[MAX_SIZE];
    node_pointer seq[MAX_SIZE];
    node_pointer x, y, top;
    int n;

    printf("Enter the size (<= %d)", MAX_SIZE);
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        out[i] = TRUE;
        seq[i] = NULL;
    }

    /* phase 1 */
    int i, j;
    printf("Enter a pair of numbers (-1 -1 to quit): ");
    scanf("%d %d", &i, &j);
    while (i >= 0){
        x = (node_pointer)malloc(sizeof(struct node));
        x->data = j;
        x->link = seq[i];
        seq[i] = x;
        x = (node_pointer)malloc(sizeof(struct node));
        x->data = i;
        x->link = seq[j];
        seq[j] = x;
        printf("Enter a pair of numbers (-1 -1 to quit): ");
        scanf("%d %d", &i, &j);
    }

    /* phase 2 */
    /* 시험 전에 더 보기 */
    for (int i = 0; i < n; i++){
        if (out[i]){
            printf("\nNew Classes: %5d", i);
            out[i] = FALSE;
            x = seq[i];
            top = NULL;
            for (; ;){
                while (x){
                    j = x->data;
                    if (out[j]){
                        printf("%5d", j);
                        out[j] = FALSE;
                        y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    }
                    else x = x->link;
                }
                if (!top) break;
                x = seq[top->data];
                top = top->link;
            }
        }
    }
    printf("\n");

    return 0;
}