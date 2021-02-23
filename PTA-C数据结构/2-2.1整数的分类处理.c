#include<stdio.h>

int main()
{
	int i, N, complement, max = 3, count0 = 0, count1 = 0, sum = 0, count2 = 0;
	scanf("%d",&N);
	int a[N]; 
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++)
	{
		complement = a[i]%3;
		switch(complement)
		{
			case 0:
				if(a[i]>=max) 
				{
					count0++;
					max = a[i];
				}
				break;
			case 1:
				count1++; break;
			case 2:
				sum+=a[i]; count2++; break;
			default:
				printf("“Ï≥£"); break;	
		}
	}
	count0==0?printf("NONE "):printf("%d ",max);
	count1==0?printf("NONE "):printf("%d ",count1);
	count2==0?printf("NONE"):printf("%f",(float)sum/count2);
	return 0;

} 
