#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100] = "dog";
    char t[] = "house";
    char u[] = "rainbow";
    printf("%s\n", s);
    printf("%s\n", t);
    printf("%s\n", u);
    // char s[] = "dogs" 하고 strcat(s, u); 하면 안됨
    // s에 동적으로 메모리를 할당하거나 size를 미리 정해줘야 함
    strcat(s, u); // s의 마지막 NULL문자를 u의 첫 문자가 덮어씀
    printf("%s\n", s);
    printf("%s\n", t);

    return 0;
}