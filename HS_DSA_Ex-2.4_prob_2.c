#include <stdio.h>
#define MAX_TERMS 100 /*size of terms array*/
typedef struct{
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;
void readpoly(int nterms)
{
	if(nterms>MAX_TERMS)
		printf("The number of terms exceeds size of array");
	else
	{
		int i;
		printf("Enter coefficient of %dth term",1);
		scanf("%f",&terms[avail].coef);
		printf("Enter exponent of %dth term",1);
		scanf("%d",&terms[avail].expon);
		for(i=1;i<nterms;i++)
		{
			printf("Enter coefficient of %dth term",(i+1));
			scanf("%f",&terms[avail+i].coef);
			do {
                printf("Enter exponent of %dth term", i + 1);
                scanf("%d", &terms[avail+i].expon);
                if (terms[avail+i].expon >= terms[avail+i - 1].expon)
                printf("Exponent must be less than the previous one. Try again.\n");
                }while (terms[avail+i].expon >= terms[avail+i - 1].expon);
        }
		avail=avail+nterms;
	}
}
void printpoly(int start, int finish)
{
	int i;
	for(i=start;i<=finish;i++)
	{
		printf("Coefficient of %dth term is %f\n",(i-start+1),terms[i].coef);
		printf("Exponent of %dth term is %d\n",(i-start+1),terms[i].expon);
	}
}