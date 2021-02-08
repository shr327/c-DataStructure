#include <stdio.h>

void Permutation(int *arr, int n, int turn);

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	Permutation(arr, n, 0);
	return 0;
}

void Permutation(int *arr, int n, int turn)
{
	int i, j;
	if(turn==n)
	{
		for(i=0;i<n;i++) printf("%d",arr[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<turn;j++) if(arr[j]==i) break;
		if(j==turn)
		{
			arr[turn] = i;
			Permutation(arr, n, turn+1);
		}
	}
}
