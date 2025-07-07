#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 1000

void all_comb(bool tval[],int begin,int n)
{
	if (begin == n) {
        for (int i = 0; i < n; i++) {
            printf("%c ", tval[i] ? 'T' : 'F');
        }
        printf("\n");
	}
	else
	{
		tval[begin]=true;
		all_comb(tval,begin+1,n);
		tval[begin]=false;
		all_comb(tval,begin+1,n);
	}
}


int main()
{
	int n;bool tval[MAXSIZE];
	printf("Enter no. of Boolean variables");
	scanf("%d",&n);
	all_comb(tval,0,n);
	return 0;
}