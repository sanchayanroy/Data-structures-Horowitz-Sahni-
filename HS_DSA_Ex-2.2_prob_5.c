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
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void transpose(int **a, int rows)
{
    int i, j, temp;
    for (i = 0; i < rows - 1; i++)
        for (j = i + 1; j < rows; j++)
            SWAP(a[i][j], a[j][i], temp);
}
