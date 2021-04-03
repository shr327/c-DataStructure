#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Comp(const void*a, const void*b);
int GetLeftSize(int N);
void BuildTree(int Data[], int Tree[], int Left, int Right, int p);

int main()
{
	int i, N;
	scanf("%d", &N);
	int Data[N+1], Tree[N+1];
	Data[0] = -1;
	for(i=1;i<=N;i++) scanf("%d", &Data[i]);
	qsort(Data, N+1, sizeof(int), Comp);
	BuildTree(Data, Tree, 1, N, 1);
	printf("%d", Tree[1]);
	for(i=2;i<=N;i++) printf(" %d", Tree[i]);
	printf("\n");
}

int Comp(const void*a, const void*b)
{
	return *(const int*)a-*(const int*)b;
}

int GetLeftSize(int N)
{
	int h, max, x;
	h = log(N+1)/log(2);
	max = pow(2, h-1);
	x = N+1-2*max;
	return (x<max?x:max)+max-1;
}

void BuildTree(int Data[], int Tree[], int Left, int Right, int p)
{
	int N = Right-Left+1;
	if(!N) return;
	int leftsize = GetLeftSize(N);
	Tree[p] = Data[Left+leftsize];
	BuildTree(Data, Tree, Left, Left+leftsize-1, p*2);
	BuildTree(Data, Tree, Left+leftsize+1, Right, p*2+1);
}
