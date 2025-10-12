#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
#define MAX_COL 10

typedef struct{
    int row;
    int col;
    int value;
} term;

void printMatrix(term*);
void fast_transpose(term*, term*);

int main()
{
    term a[MAX_TERMS]; term b[MAX_TERMS];
    a[0].row = 6; a[0].col = 6; a[0].value = 8;  // # of rows, # or cols, # of terms
    a[1].row = 0; a[1].col = 0; a[1].value = 15;
    a[2].row = 0; a[2].col = 3; a[2].value = 22;
    a[3].row = 0; a[3].col = 5; a[3].value = -15;
    a[4].row = 1; a[4].col = 1; a[4].value = 11;
    a[5].row = 1; a[5].col = 2; a[5].value = 3;
    a[6].row = 2; a[6].col = 3; a[6].value = -6;
    a[7].row = 4; a[7].col = 0; a[7].value = 91;
    a[8].row = 5; a[8].col = 2; a[8].value = 28;

    b[0].row = 0; b[0].col = 0; b[0].value = 0;

    printMatrix(a);
    fast_transpose(a, b);
    printMatrix(b);

    return 0;
}

void printMatrix(term *m){
    int iter = 1;
    int rows = m[0].row; int cols = m[0].col; int num_terms = m[0].value;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (iter < num_terms && m[iter].row == i && m[iter].col == j){ // i,j에 value가 있는지
                printf("%3d", m[iter].value);
                iter++;
            }
            else
                printf("%3d", 0);
        }
        printf("\n");
    }
    printf("\n");
}

void fast_transpose(term *a, term *b){
    int row_terms[MAX_COL]; int starting_pos[MAX_COL];
    int num_cols = a[0].col;
    int num_terms = a[0].value;

    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;
    
    if (num_terms > 0){
        for (int i = 0; i < num_cols; i++)
            row_terms[i] = 0;
        for (int i = 1; i <= num_terms; i++)
            row_terms[a[i].col]++; // 원본 matrix의 각 열에 element가 몇 개 있는지 확인
        starting_pos[0] = 1;
        for (int i = 1; i < num_cols; i++)
            starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
        for (int i = 1; i <= num_terms; i++){
            int j = starting_pos[a[i].col]++;
            b[j].col = a[i].row;
            b[j].row = a[i].col;
            b[j].value = a[i].value;
        }
    }
}