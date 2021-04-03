#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 100000
#define MIN -100000

typedef enum{false, true} bool;

typedef struct HNode* MinHeap;

typedef int ElementType;

struct HNode{
	int Capacity;
	int Size;
	ElementType *Data;
};

bool IsFull(MinHeap H)
{
	return H->Size == H->Capacity; 
}

MinHeap CreateHeap()
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Capacity = MAXN;
	H->Size = 0;
	H->Data = (ElementType*)malloc((MAXN+1)*sizeof(ElementType));
	H->Data[0] = MIN;
	return H;
}

bool Insert(MinHeap H, ElementType X)
{
	int i;
	if(IsFull(H)) return false;
	i = ++H->Size;
	for(;H->Data[i/2]>X;i/=2) H->Data[i] = H->Data[i/2];
	H->Data[i] = X;
	return true;
}

int Find(MinHeap H, int X)
{
	int i=1;
	for(i;H->Data[i]!=X;i++);
	return i;
}

int main()
{
	MinHeap H = CreateHeap();
	int i, N, M, X;
	scanf("%d %d",&N, &M);
	for(i=0;i<N;i++)
	{
		scanf("%d",&X);
		Insert(H, X);
	}
	int num1, num2;
	char s1[MAXN], s2[MAXN];
	char remain[MAXN];
	char leap[MAXN];
	for(i=0;i<M;i++)
	{
		scanf("%d",&num1);
		scanf("%s",s1);
		if(!strcmp("and", s1))
		{
			scanf("%d",&num2);
			if(Find(H,num1)/2==Find(H,num2)/2) printf("T\n");
			else printf("F\n");
			gets(remain);
		}
		else
		{
			scanf("%s %s",s1,s2);
			if(!strcmp(s2,"root"))
			{
				if(num1 == H->Data[1]) printf("T\n");
				else printf("F\n");
				gets(remain);
			}
			if(!strcmp(s2,"parent"))
			{
				scanf("%s",leap);
				scanf("%d",&num2);
				if(Find(H, num2)/2==Find(H, num1)) printf("T\n");
				else printf("F\n");
				gets(remain);
			}
			if(!strcmp(s2,"child"))
			{
				scanf("%s",leap);
				scanf("%d",&num2);
				if(Find(H, num1)/2==Find(H, num2)) printf("T\n");
				else printf("F\n");
				gets(remain);
			}
		}
	}
	return 0;
}
 
