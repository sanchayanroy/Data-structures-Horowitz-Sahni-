#include <stdio.h>
#define MAX_TERMS 100 /*size of terms array*/
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


void pmult(int startA, int finishA, int startB, int finishB)
{
    int i, j;
    int startx = avail, finishx = avail + finishB-startB;
    int starty, finishy;
    int startD, finishD;  // declare as integers, not pointers

    for (i = startA; i <= finishA; i++)
    {
        for (j = startB; j <= finishB; j++)
            attach(terms[i].coef * terms[j].coef, terms[i].expon + terms[j].expon);

        if (i == startA)
			continue;
		
        starty = avail - (finishB - startB + 1);
        finishy = avail - 1;

        padd(startx, finishx, starty, finishy, &startD, &finishD);

        startx = startD;
        finishx = finishD;
    }
}
