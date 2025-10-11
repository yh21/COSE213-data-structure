#include <stdio.h>
#include <string.h>

int main()
{
    typedef struct{
        char name[10];
        int age;
        float salary;
    } person; // ; 안빼뜨리기

    person p1;
    strcpy(p1.name, "yh");
    p1.age = 20;
    p1.salary = 200000;

    printf("%s\n", p1.name);
    printf("%d\n", p1.age);
    printf("%f", p1.salary);

    return 0;
}