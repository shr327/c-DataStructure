#include<stdio.h>

int main()
{
	
	int i, j, N;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i!=j) sum+=a[i]*10+a[j];
		}
	}
	printf("%d",sum);
	return 0;
}
