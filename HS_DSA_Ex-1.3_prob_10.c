#include <stdio.h>
#define MAXSIZE 100


long recursive_ackerman(int m,int n)
{
	if(m==0)
		return n+1;
	else if(n==0)
		return recursive_ackerman(m-1,1);
	else
		return recursive_ackerman(m-1,recursive_ackerman(m,n-1));
}

long iterative_ackerman(int m,int n)//The implementation is wrong
{
	long ar[MAXSIZE][MAXSIZE];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0)
				ar[i][j]=j+1;
			else if(j==0)
				ar[i][j]=ar[i-1][1];
			else
			{
				if (ar[i][j-1] >= MAXSIZE) 
				{
                 printf("Value exceeds array bounds — cannot compute safely.\n");
                 return -1;
	            }
               ar[i][j]=ar[i-1][ar[i][j-1]];
			}
		}
	}
	return ar[m][n];
}
int main()
{
	int m, n;
	printf("Enter any two arbitrary non-negative integers");
	scanf("%d %d",&m,&n);
	if (m > 3 || (m == 3 && n > 10)) 
    printf("Warning: This input may cause a stack overflow.\n");
	printf("Recursive A(%d, %d) = %ld\n", m, n, recursive_ackerman(m, n));
    printf("Iterative A(%d, %d) = %ld\n", m, n, iterative_ackerman(m, n));
	return 0;
}