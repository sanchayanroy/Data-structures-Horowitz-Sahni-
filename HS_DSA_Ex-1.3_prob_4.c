#include <stdio.h>


void sort_three(int x,int y,int z)
{
	if(x>=y)
	{
		if(z>=x)
			printf("x,y,z in ascending order is %d %d %d",y,x,z);
		else
		{
			if(z>=y)
				printf("x,y,z in ascending order is %d %d %d",y,z,x);
			else
				printf("x,y,z in ascending order is %d %d %d",z,y,x);
		}
	}
	else
	{
		if(z<=x)
			printf("x,y,z in ascending order is %d %d %d",z,x,y);
		else
		{
			if(z>=y)
				printf("x,y,z in ascending order is %d %d %d",x,y,z);
			else
				printf("x,y,z in ascending order is %d %d %d",x,z,y);
		}
	}
}


int main()
{
	int x,y,z;
	printf("Enter the values of x,y,z respectively");
	scanf("%d %d %d",&x,&y,&z);
	sort_three(x,y,z);
	return 0;
}