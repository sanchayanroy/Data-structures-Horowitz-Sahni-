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


int** make2DArray(int rows, int length[])
{
int **x,i;
MALLOC(x,rows*sizeof(*x));
for(i=0;i<rows;i++)
	CALLOC(x[i],length[i],sizeof(**x));
return x;
}