#include <stdio.h>
#define MAX_TERMS 100 /*size of terms array*/
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)
typedef struct{
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;

void attach(float coefficient, int exponent)
{
	/* add a new term to the polynomial*/
	if(avail>=MAX_TERMS)
	{
		fprintf(stderr,"Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef=coefficient;
	terms[avail++].expon=exponent;
}
void padd(int startA,int finishA,int startB, int finishB, int *startD,int *finishD)
{
	/* add A(x) and B(x) to obtain D(x)*/
	float coefficient;
	*startD=avail;
	while(startA<=finishA&&startB<=finishB)
		switch(COMPARE(terms[startA].expon,terms[startB].expon)){
			case -1: /*a expon < b expon*/
			  attach(terms[startB].coef,terms[startB].expon);
			  startB++;
			  break;
			case 0:/* equal exponents*/
			  coefficient=terms[startA].coef+terms[startB].coef;
			  if(coefficient)
				  attach(coefficient,terms[startA].expon);
              startA++;			  
			  startB++;
              break;
            case 1: /*a expon > b expon*/
			  attach(terms[startA].coef,terms[startA].expon);
			  startA++;
			  break;
        }
    /*add in remaining terms of A(x)*/
    for(;startA<=finishA;startA++)
       attach(terms[startA].coef,terms[startA].expon);
    /*add in remaining terms of B(x)*/
    for(;startB<=finishB;startB++)
       attach(terms[startB].coef,terms[startB].expon);
	*finishD=avail-1;
}