#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
void strnins(char*, char*, int);

int main()
{
    char s[MAX_SIZE] = "amobile";
    char t[MAX_SIZE] = "uto";
    strnins(s, t, 1);
    printf("%s", s); // strnins 함수를 사용하면 s에 저장됨
    return 0;
}

void strnins(char *s, char *t, int i)
{
    char string[MAX_SIZE] = {'\0'}; // string을 NULL로 초기화
    char *temp = string;

    if (i < 0 || i > strlen(s)){
        fprintf(stderr, "position is out of bounds.\n"); exit(1);
    }
    if (!strlen(s)) strcpy(s, t);
    else if (strlen(t)){
        strncpy(temp, s, i);
        // strlen(s) > i면 temp 뒤에 자동으로 '\0'이 붙지 않음
        // string을 NULL로 초기화 안했으면 dummy값에 NULL이 있어서 문자열이 이상하게 들어갈 수도 있음
        strcat(temp, t);
        strcat(temp, (s + i));
        strcpy(s, temp);
    }

}