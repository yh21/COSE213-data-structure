#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nfind(char *str, char *pat); // 함수 선언할 때 ; 포함, str, pat은 안써도 상관없음 (char*, char*)

int main()
{
    char str[] = "hello world!";
    char pat[] = "wor";
    int rv;

    rv = nfind(str, pat);

    if (rv == -1)
        printf("The pattern was not found in string");
    else
        printf("The pattern was found at position %d", rv);

    return 0;
}

int nfind(char *str, char *pat){
    int i, j, start = 0;
    int lens = strlen(str) - 1;
    int lenp = strlen(pat) - 1;
    int endmatch = lenp;
    for (i = 0; endmatch <= lens; endmatch++, start++){
        if (str[endmatch] == pat[lenp]){ // string 구간의 마지막 문자와 pattern의 마지막 문자를 먼저 비교
            for (j = 0, i = start; j < lenp && str[i] == pat[j]; i++, j++)
                ;
        }
        if (j == lenp)
            return start;
    }
    return -1;
}