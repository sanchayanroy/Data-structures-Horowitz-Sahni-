#include <stdio.h>

#include<stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define COMPARE(x,y) (((x)<(y))?-1:((x)==(y))?0:1)
void sort(int[],int);//selection sort
int binsearch(int[],int,int,int);
void main()
{
	int i,n;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate:");
	scanf("%d",&n);
	if(n<1||n>MAX_SIZE)
	{
		fprintf(stderr, "Improper value of n");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<n;i++)
	{
	  printf("Enter the array elements");
	  scanf("%d",&list[i]);
	}
	sort(list,n);
	int search;
	printf("Enter an arbitary element to be searched");
	scanf("%d",&search);
	int pos=binsearch(list,search,0,n-1);
	if(pos!=-1)
		printf("The element %d has been found in the position %d",search,(pos));
	else
		printf("The element %d has not been found",search);
}
int binsearch(int list[],int searchnum,int left,int right)
{
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		switch(COMPARE(list[middle],searchnum))
		{
			case -1:
			left=middle+1;
			break;
			case 0:
			return middle;
			case 1:
			right=middle-1;
		}
	}
	return -1;
}




void sort(int list[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(list[j]<list[min])
				min=j;
		}
		SWAP(list[i],list[min],temp);
	}
}