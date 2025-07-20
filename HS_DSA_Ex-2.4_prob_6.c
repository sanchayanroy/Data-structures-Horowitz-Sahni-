#define MAX_TERMS 101 /*maximum number of terms+1*/
#define MAX_POLYS 15 /* maximum number of polynomials*/

typedef struct{
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_POLYS][MAX_TERMS];

int row_index=0;
void readPoly(int nterms)
{
	if(nterms>MAX_TERMS-1)
		printf("Polynomial is too large");
	else
	{
		terms[row_index][0].expon=nterms;
		int j;
		for(j=1;j<=nterms;j++)
		{
			printf("Enter coefficient of %dth of polynomial %d\n",j,(row_index+1));
			scanf("%f",&terms[row_index][j].coef);
			if(j==1)
			{
				printf("Enter exponent of %dth term of polynomial %d\n",j,(row_index+1));
                scanf("%d", &terms[row_index][j].expon);
				continue;
			}
			do {
                printf("Enter exponent of %dth term of polynomial %d\n",j,(row_index+1));
                scanf("%d", &terms[row_index][j].expon);
                if (terms[row_index][j].expon >= terms[row_index][j-1].expon)
                printf("Exponent must be less than the previous one. Try again.\n");
                }while (terms[row_index][j].expon >= terms[row_index][j-1].expon);
		}
		row_index++;
	}
}


void printpoly(int poly_index)
{
	int i;
	for(i=1;i<=terms[poly_index][0].expon;i++)
	{
		printf("Coefficient of %dth term of polynomial %d is %f\n",i,(poly_index+1),terms[poly_index][i].coef);
		printf("Exponent of %dth term of polynomial %d is %d\n",i,(poly_index+1),terms[poly_index][i].expon);
	}
}




void attach(int col_index, float coefficient, int exponent)
{
	/* add a new term to the polynomial*/
	if(row_index>MAX_POLYS)
	{
		fprintf(stderr,"Too many polynomials\n");
		exit(EXIT_FAILURE);
	}
	if(col_index>MAX_TERMS)
	{
		fprintf(stderr,"Too many terms\n");
		exit(EXIT_FAILURE);
	}
	terms[row_index][col_index].coef=coefficient;
	terms[row_index][col_index].expon=exponent;
}
void padd(int poly_indexA, int poly_indexB)
{
	/* add A(x) and B(x)*/
	int startA=1,finishA=terms[poly_indexA][0].expon;
	int startB=1,finishB=terms[poly_indexB][0].expon;
	int col_index=1;//Current col_index of sum polynomial
	float coefficient;
	while(startA<=finishA&&startB<=finishB)
		switch(COMPARE(terms[poly_indexA][startA].expon,terms[poly_indexB][startB].expon)){
			case -1: /*a expon < b expon*/
			  attach(col_index,terms[poly_indexB][startB].coef,terms[poly_indexB][startB].expon);
			  startB++;
			  col_index++;
			  break;
			case 0:/* equal exponents*/
			  coefficient=terms[poly_indexA][startA].coef+terms[poly_indexB][startB].coef;
			  if(coefficient)
				  attach(col_index,coefficient,terms[poly_indexA][startA].expon);
              startA++;			  
			  startB++;
			  col_index++;
              break;
            case 1: /*a expon > b expon*/
			  attach(col_index,terms[poly_indexA][startA].coef,terms[poly_indexA][startA].expon);
			  startA++;
			  col_index++;
			  break;
        }
    /*add in remaining terms of A(x)*/
    for(;startA<=finishA;startA++)
	{
       attach(col_index,terms[poly_indexA][startA].coef,terms[poly_indexA][startA].expon);
	   col_index++;
	}
    /*add in remaining terms of B(x)*/
    for(;startB<=finishB;startB++)
	{
       attach(col_index,terms[poly_indexB][startB].coef,terms[poly_indexB][startB].expon);
	   col_index++;
	}
	terms[row_index][0]=col_index-1;
    row_index++;
}

void attach_mult(int rowindex,int colindex, float coefficient, int exponent)
{
	/* add a new term to the polynomial*/
	if(rowindex>MAX_POLYS)
	{
		fprintf(stderr,"Too many polynomials\n");
		exit(EXIT_FAILURE);
	}
	if(colindex>MAX_TERMS)
	{
		fprintf(stderr,"Too many terms\n");
		exit(EXIT_FAILURE);
	}
	terms[rowindex][colindex].coef=coefficient;
	terms[rowindex][colindex].expon=exponent;
}


void pmult(int poly_indexA,int poly_indexB)
{
	int startA=1,finishA=terms[poly_indexA][0].expon;
	int startB=1,finishB=terms[poly_indexB][0].expon;
    int i, j;
    int ind1=row_index,ind2=row_index+1;
    for (i = startA; i <= finishA; i++)
    {
		for (j = startB; j <= finishB; j++)
            attach_mult(ind2,j,terms[poly_indexA][i].coef * terms[poly_indexB][j].coef, terms[poly_indexA][i].expon + terms[poly_indexB][j].expon);
		if (i == startA) 
		{
		 terms[ind1][0]=finishB;
         for (j = startB; j <= finishB; j++)
		 {
             terms[ind1][j].coef = terms[ind2][j].coef;
			 terms[ind1][j].expon=terms[ind2][j].expon;
		 }
         continue;
        }
		terms[ind2][0].expon=finishB;
        row_index=row_index+2;
        padd(ind1,ind2);
        row_index--;
		for(j=0;j<=terms[row_index][0];j++)
		{
			terms[ind1][j].coef=terms[row_index][j].coef;
			terms[ind1][j].expon=terms[row_index][j].expon;
		}
		row_index=row_index-2;
		ind1=row_index;
		ind2=row_index+1;
    }
}



