#include <stdio.h>
#include <stdbool.h>

bool check_perf(int n)
{
	int i,sum=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
			sum=sum+i;
	}
	if(sum==n)
		return true;
	else
		return false;
}

int main()
{
	int n;
	printf("Enter any arbitrary integer");
	scanf("%d",&n);
	if(check_perf(n))
		printf("%d is a perfect number",n);
	else
		printf("%d is not a perfect number",n);
	return 0;
}