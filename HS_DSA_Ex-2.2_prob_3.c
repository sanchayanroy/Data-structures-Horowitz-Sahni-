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


void add(int **a,int **b,int **c,int rows, int cols)
{
int i,j;
MALLOC(c,rows*sizeof(*c));
for(i=0;i<rows;i++)
	CALLOC(c[i],cols,sizeof(**c));
for(i=0;i<rows;i++)
	for(j=0;j<cols;j++)
		c[i][j]=a[i][j]+b[i][j];
}
