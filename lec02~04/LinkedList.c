#include <stdio.h>

struct list{
    char data;
    struct list *link;
};

int main()
{
    struct list l1, l2, l3;
    l1.data = 'a', l2.data = 'b', l3.data = 'c';
    l1.link = l2.link = l3.link = NULL;

    l1.link = &l2;
    l2.link = &l3;
    return 0;
}