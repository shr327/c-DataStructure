#include<stdio.h>
#include<math.h> 

int main()
{
	int N;
	scanf("%d",&N);
	int i, sum=0, a[N];
	for(i=0; i<N; i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	double aver = (double)sum/N, sum2 = 0;
	for(i=0; i<N; i++)
	{
		sum2 += pow(a[i]-aver,2);
	}
	printf("%.5f",pow(sum2/N,0.5));
	
	return 0;
}



