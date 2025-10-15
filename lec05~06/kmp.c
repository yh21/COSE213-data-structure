#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

int failure[MAX_PATTERN_SIZE];
char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];

void fail(char*);
int pmatch(char*, char*);

int main()
{
    int rv;
    strcpy(string, "ababcabcabababdabaabaabacabaababaaabaabaacaaba");
    strcpy(pat, "abaababaaaba");

    fail(pat);
    rv = pmatch(string, pat);

    printf("%d", rv);
    return 0;
}

void fail(char *pat){
    int lenp = strlen(pat);
    failure[0] = -1;
    for (int j = 1; j < lenp; j++){
        int i = failure[j - 1];
        while ((pat[j] != pat[i + 1]) && (i >= 0))
            i = failure[i];
        if(pat[j] == pat[i + 1])
            failure[j] = i + 1;
        else
            failure[j] = -1;
    }
}

int pmatch(char *string, char *pat){
    int lens = strlen(string); int lenp = strlen(pat);
    int i = 0, j = 0;
    while (i < lens && j < lenp){
        if (string[i] == pat[j])
            i++, j++;
        else if (j == 0)
            i++;
        else
            j = failure[j - 1] + 1;
    }
    return ((j == lenp) ? (i - lenp) : -1);
}