#include <stdio.h>
#define MAXSIZE 1000

long Horner_Rule(int coeff[],int n,int begin,int x_0)
{
	if(begin==n-1)
		return coeff[begin];
	else
		return coeff[begin]+x_0*Horner_Rule(coeff,n,begin+1,x_0);
}


int main()
{
int n,x_0,i;
printf("Enter the number of coefficients");
scanf("%d",&n);
int coeff[MAXSIZE];
for(i=0;i<n;i++)
{
	printf("Enter coefficient a_%d",i);
	scanf("%d",&coeff[i]);
}
printf("Enter the value at which the polynomial is to be evaluated");
scanf("%d",&x_0);
printf("The horner rule evaluated at %d returns the value %ld",x_0,Horner_Rule(coeff,n,0,x_0));
return 0;
}