#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10
#define INVAlID -1

typedef struct{
    int data;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element);
element pop();
void stackfull();
element stackempty();

int main()
{
    element e;
    for (int i = 0; i < 7; i++){
        e.data = i;
        push(e);
        printf("data %d is inserted in stack!\n", e.data);
    }

    for (int i = 0; i < 12; i++){
        e = pop();
        printf("%d is deleted from the stack\n", e.data);
    }

    return 0;
}

void push(element item){
    if (top >= MAX_STACK_SIZE - 1)
        stackfull();
    stack[++top] = item;
}

void stackfull(){
    fprintf(stderr, "stack is full, cannot add element.\n");
    exit(EXIT_FAILURE);  // exit(1)
}

element pop(){
    if (top == -1)
        return stackempty();
    return stack[top--]; // pop()함수는 stack 안의 element들은 그대로 유지하고 top만 -= 1
}                        // return 할 때도 stack[top]을 return해서 main함수에서 e는 stack[top]

element stackempty(){
    element e;
    e.data = INVAlID;
    return e;            // -1은 INVALID값
}