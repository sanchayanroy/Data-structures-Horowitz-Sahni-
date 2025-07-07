#include<stdio.h>

void recursive_towerOfHanoi(int n, int from, int to, int aux) {
        if(n==0)
        return;
        else
        {
        recursive_towerOfHanoi(n-1,from,aux,to);
		printf("Disk %d is moved from tower %d to %d\n",n,from,to);
        recursive_towerOfHanoi(n-1,aux,to,from);
        }
    }
	
int main()
{
	int n;
	printf("Enter no. of disks");
	scanf("%d",&n);
	recursive_towerOfHanoi(n,1,3,2);
	return 0;
}