#include<stdio.h>

int MidNum(int a[], int b[], int N); 

int main()
{
	int i, N;
	scanf("%d",&N);
	int a[N], b[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("%d",MidNum(a, b, N));
	return 0; 
}

int MidNum(int a[], int b[], int N)
{
	int count = 0;
	int i=0, j=0;
	for(i;i<N;i++)
	{
		for(j;j<N;j++)
		{
			if(a[i]>b[j])
			{
				if(count == N-1) return b[j];
				count++;
			}
			else
			{
				if(count == N-1) return a[i];
				count++;
				break;
			}
		}
	}
}
