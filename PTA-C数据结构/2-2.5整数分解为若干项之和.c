#include<stdio.h>

int cnt, N, a[30];

void numrecursion(int num, int location, int sum)
{
	if(sum==N)
	{
		cnt++;
		printf("%d=",N);
		printf("%d",a[0]);
		int i;
		for(i=1; i<location; i++)
		{
			printf("+%d",a[i]);
		}
		if(cnt%4==0 && cnt!=0) printf("\n");
		else if(num!=N) printf(";");
		return ;
	}
	if(sum>N) return;
	if(sum<N)
	{
		int i;
		for(i=num; i<=N; i++)
		{
			a[location] = i;
			numrecursion(i, location+1, sum+i);
		}
	}
}

int main()
{
	scanf("%d",&N);
	numrecursion(1,0,0);
	return 0;
}

void numrecursion(int num, int location, int sum)
{
	
}








