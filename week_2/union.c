#include <stdio.h>

typedef struct{
    enum tagField {pitcher, hitter} role;
    union{
        int SO;
        int HR;
    }u;
} playerType;

typedef struct{
    char name[10];
    int age;
    playerType playerInfo;
} baseballPlayer;

int main()
{
    baseballPlayer p1, p2;
    p1.playerInfo.role = pitcher;
    p2.playerInfo.role = hitter;
    p1.playerInfo.u.SO = 163;
    p2.playerInfo.u.HR = 24;

    printf("%d\n", p1.playerInfo.u.SO);

    return 0;
}