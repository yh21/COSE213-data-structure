#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct{
    char name[10];
    int age;
    float salary;
} humanBeing;

int humans_Equal(humanBeing, humanBeing);

int main()
{
    humanBeing h1, h2;
    strcpy(h1.name, "yh");
    h1.age = 20;
    h1.salary = 1000000;
    strcpy(h2.name, "km");
    h2.age = 20;
    h2.salary = 10;

    if (humans_Equal(h1, h2))
        printf("same person");
    else
        printf("differnet person");

    return 0;
}

int humans_Equal(humanBeing h1, humanBeing h2){
    if (strcmp(h1.name, h2.name)) // strcmp는 문자열이 같으면 0을, 다르면 0이 아닌 값을 반환
        return FALSE;
    if (h1.age != h2.age)
        return FALSE;
    if (h1.salary != h2.salary)
        return FALSE;
    return TRUE;
}

