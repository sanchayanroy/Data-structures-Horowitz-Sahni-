#include <stdio.h>
int iterative_nthFibonacci(int n) {
        int f_i=0;
        if(n==0)
        return f_i;
        int f_j,f_k;
        f_j=1;
        if(n==1)
        return f_j;
        for(int i=2;i<=n;i++)
        {
            f_k=f_i+f_j;
            f_i=f_j;
            f_j=f_k;
        }
        return f_k;
    }
int recursive_nthFibonacci(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else 
		return recursive_nthFibonacci(n-1)+recursive_nthFibonacci(n-2);
}

int main()
{
	int n;
	printf("Enter any arbitrary non-negative integer");
	scanf("%d",&n);
    printf("The %dth Fibonacci number computed iteratively is %d\n",n,iterative_nthFibonacci(n));
    printf("The %dth Fibonacci number computed recursively is %d",n,recursive_nthFibonacci(n));	
	return 0;
}