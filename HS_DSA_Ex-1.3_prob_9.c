#include <stdio.h>
long iterative_factorial(int n) {
        int i;long p=1;
        for(i=1;i<=n;i++)
        {
            p=p*i;
        }
        return p;
    }

long iterative_binomial_coefficient(int n,int k)
{
	return iterative_factorial(n)/(iterative_factorial(n-k)*iterative_factorial(k));
}

long recursive_binomial_coefficient(int n,int k)
{
	if(k==0)
		return 1;
	else if(n==k)
		return 1;
	else return recursive_binomial_coefficient(n-1,k)+recursive_binomial_coefficient(n-1,k-1);
}




int main()
{
	int n,k;
	printf("Enter the total no. of objects");
	scanf("%d",&n);
	printf("Enter the no. of objects to be chosen");
	scanf("%d",&k);
	if(k > n || n < 0 || k < 0) {
    printf("Invalid input.\n");
    return 1;
}
	printf("The binomial coefficient computed iteratively for the variables %d and %d is %ld\n",n,k,iterative_binomial_coefficient(n,k));
	printf("The binomial coefficient computed recursively for the variables %d and %d is %ld\n",n,k,recursive_binomial_coefficient(n,k));
	return 0;
}