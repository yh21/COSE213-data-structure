#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
#define COMPARE(x, y) (x < y ? -1 : (x > y ? 1 : 0))

void polynomial_add(int, int, int, int, int*, int*);
void polynomial_print(int, int);
void attach(int, int);

typedef struct{
    int coef;
    int expo;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

int main()
{
    int starta, finisha, startb, finishb, startc, finishc;
    starta = avail;
    terms[avail].expo = 1000; terms[avail].coef = 2;
    avail++;
    terms[avail].expo = 0; terms[avail].coef = 1;
    finisha = avail;
    avail++;

    startb = avail;
    terms[avail].expo = 4; terms[avail].coef = 1;
    avail++;
    terms[avail].expo = 3; terms[avail].coef = 10;
    avail++;
    terms[avail].expo = 2; terms[avail].coef = 3;
    avail++;
    terms[avail].expo = 0; terms[avail].coef = 1;
    finishb = avail;
    avail++;

    polynomial_add(starta, finisha, startb, finishb, &startc, &finishc);
    polynomial_print(startc, finishc);

    return 0;
}

void polynomial_add(int starta, int finisha, int startb, int finishb, int *startd, int *finishd) {
  /* add a(x) and b(x) to obtain d(x) */
  int coefficient;
  *startd = avail;
  while(starta <= finisha && startb <= finishb)
    switch(COMPARE(terms[starta].expo, terms[startb].expo)) {
      case -1:
        attach(terms[startb].coef, terms[startb].expo);
        startb++;
        break;
      case 0:
        coefficient = terms[starta].coef + terms[startb].coef;
        if(coefficient) attach(coefficient, terms[starta].expo);
        starta++; startb++;
        break;
      case 1:
        attach(terms[starta].coef, terms[starta].expo);
        starta++;
    }
  /* add in remaining terms of a(x) */
  for( ; starta <= finisha; starta++)
    attach(terms[starta].coef, terms[starta].expo);
  /* add in remaining terms of b(x) */
  for( ; startb <= finishb; startb++)
    attach(terms[startb].coef, terms[startb].expo);
  *finishd = avail-1;
}

void attach(int coefficient, int exponent) {
  /* add a new term to the polynomial */
  if(avail >= MAX_TERMS) {
    fprintf(stderr, "too many terms in the polynomial"); exit(1);
  }
  terms[avail].coef = coefficient;
  terms[avail++].expo = exponent;
}

void polynomial_print(int starta, int finisha) {

  int i;
  for(i = starta; i <= finisha; i++) {
    if(i == starta) printf("%dx^%d", terms[i].coef, terms[i].expo);
    else printf(" + %dx^%d", terms[i].coef, terms[i].expo);
  }
  printf("\n");
}

