#include <stdio.h>

long iterative_factorial(int n) {
        int i;long p=1;
        for(i=1;i<=n;i++)
        {
            p=p*i;
        }
        return p;
    }
	
	
long recursive_factorial(int n)
{
	if(n==0)
		return 1;
	else return n* recursive_factorial(n-1);
}

int main()
{
	int n;
	printf("Enter an arbitrary non-negative integer");
	scanf("%d",&n);
	if(n>-1)
	{
		printf("The factorial of the number %d computed iteratively is %ld\n",n,iterative_factorial(n));
		printf("The factorial of the number %d computed recursively is %ld\n",n,recursive_factorial(n));
	}
	else
		printf("Input is not valid\n");
	return 0;
}