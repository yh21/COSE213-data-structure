#include <stdio.h>
#include <stdlib.h>

int** make2dArray(int, int);

int main(){

    int **matrix;
    matrix = make2dArray(5, 5);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = i*5 + j + 1;
            printf("%p: %2d ", &matrix[i][j], matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int** make2dArray(int row, int col){
    int **x;
    x = malloc(row * sizeof(*x));
    printf("%lu\n", sizeof(*x));
    printf("%lu\n", sizeof(**x));
    printf("x allocated at address %p\n", x);

    for(int i = 0; i < row; i++)  {
        x[i] = malloc(col*sizeof(**x));
        printf("x[%2d] allocated at address %p\n", i, x[i]);
    }

    return x;
}