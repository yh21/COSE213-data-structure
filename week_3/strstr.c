#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char pat[] = "world";
    char str[] = "Hello world I am a student.";
    char *t;
    t = strstr(str, pat);

    if(t != NULL)
        printf("The string returned by strstr is: %s\n", t); // 주소 출력하면 그 주소부터 '\0'까지 출력됨
    else
        printf("The pattern was not found with strstr.\n");

    return 0;
}