#include<stdio.h>

int main()
{
	int i, j, N;
	scanf("%d",&N);
	int a[N];
	for(i=0; i<N; i++)
	{
		scanf("%d",&a[i]);
	}
	
	int b[N];
	for(i=0; i<N; i++)
	{
		b[i] = 100;
	}
	int max=0;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(b[j]-a[i]>=0)
			{
				b[j]-=a[i];
				printf("%d %d\n",a[i],j+1);
				if(j+1>max) max = j+1;
				break;
			}
			
		}
	}
	printf("%d\n",max);
	return 0;
}
