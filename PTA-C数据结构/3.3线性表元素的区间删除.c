#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20

typedef int ElementType;
typedef struct LNode* List;

struct LNode{
	ElementType Data[MAXSIZE];
	ElementType Last;
};

List ReadInput();
List Delete(List L, ElementType minD,ElementType maxD);
void PrintList(List L);

int main()

{
	List L;
	ElementType minD, maxD;
	L = ReadInput();
	scanf("%d %d",&minD, &maxD);
	L = Delete(L, minD, maxD);
	PrintList(L);
	
	return 0;
}

List ReadInput()
{
	int i, n;
	List L = (List)malloc(sizeof(struct LNode));
	scanf("%d", &n);
	L->Last = n-1; 
	for(i=0;i<n;i++)
	{
		scanf("%d",&L->Data[i]);
		
	}
	return L;
}

void PrintList(List L)
{
	int i;
	for(i=0;i<=L->Last;i++)
	{
		printf("%d ",L->Data[i]);
	}
	free(L);
	
}

List Delete(List L, ElementType minD, ElementType maxD)
{
	int i, j;
	for(i=0;i<=L->Last;i++)
	{
		if((L->Data[i]>minD)&&(L->Data[i]<maxD))
		{
			for(j=i;j<L->Last;j++)
			{
				L->Data[j] = L->Data[j+1];
			}
			i--;
			L->Last--; 
		}
	}
	return L;
}

