#include <stdio.h>
#define MAXSIZE 100
float sum(float arr[], int n);

int main()
{
    float answer;
    float input[MAXSIZE];

    for (int i = 0; i < MAXSIZE; i++)
        input[i] = i;

    answer = sum(input, MAXSIZE);
    printf("%f", answer);

    return 0;
}

float sum(float arr[], int n){
    int i = 0;
    float tempsum = 0;

    for (int i = 0; i < MAXSIZE; i++)
        tempsum += arr[i];
    
    return tempsum;
}