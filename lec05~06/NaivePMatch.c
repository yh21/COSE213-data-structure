#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

int naivepmatch(char*, char*);
char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];

int main()
{
    int rv;
    strcpy(string, "ababcabcabababdabaabaabacabaababaaabaabaacaaba");
    strcpy(pat, "abaababaaaba");

    rv = naivepmatch(string, pat);
    printf("%d", rv);
}

int naivepmatch(char *a, char *b){
    int lens = strlen(a);
    int lenp = strlen(b);
    for (int i = 0; i < lens - lenp; i++){
        int match = 0;
        for (int j = 0; j < lenp; j++){
            if (a[i + j] == b[j])
                match++;
        }
        if (match == lenp)
            return i;
    }
    return 0;
}
