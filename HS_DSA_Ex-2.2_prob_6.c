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

void transpose(int **a, int **b, int rows, int cols)
{
	MALLOC(b,cols*sizeof(*x));
	int i,j;
	for(i=0;i<cols;i++)
		CALLOC(b[i],rows,sizeof(**x));
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			b[j][i]=a[i][j];
}