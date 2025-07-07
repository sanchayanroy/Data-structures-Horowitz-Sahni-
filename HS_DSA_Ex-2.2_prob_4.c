#include <stdio.h>
#define MALLOC(p,s)\
if(!((p)=malloc(s))){\
fprintf(stderr,"Insufficient memory");\
exit(EXIT_FAILURE);\
}
#define CALLOC(p,n,s)\
if(!((p)=calloc(n,s))){\
fprintf(stderr,"Insufficient memory");\
exit(EXIT_FAILURE);\
}

void mult(int **a, int **b, int **c, int rows)
{
	MALLOC(c,rows*sizeof(*c));
	int i,j,k;
	for(i=0;i<rows;i++)
		CALLOC(c[i],rows,sizeof(**c));
	for(i=0;i<rows;i++)
		for(j=0;j<rows;j++)
			for(k=0;k<rows;k++)
				c[i][j]+=a[i][k]*b[k][j];
}