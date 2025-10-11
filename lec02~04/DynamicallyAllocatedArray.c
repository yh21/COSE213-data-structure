#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int n;
    int *data;
    printf("How many integers do you want to generate?\n"); 
    scanf("%d", &n);

    data = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        data[i] = rand()%100;
        printf("%d\n", data[i]);
    }
    free(data);     // should return the allocated memory using free

    return 0;
}