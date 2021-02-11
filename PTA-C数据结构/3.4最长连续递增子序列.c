#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100000

typedef int ElementType;
typedef struct LNode* List;

struct LNode{
	ElementType Last;
	ElementType Data[MAXSIZE];
};

void Sub_Max(List L);
List ReadInput();
void Print(List L, ElementType Left, ElementType Right);

int main()
{
	List L=ReadInput();
	Sub_Max(L);
	return 0;
}

void Sub_Max(List L)
{
	int i, Left=0, Right=0;
	int max_l=0,max_r=0;
	for(i=0;i<=L->Last;i++)
	{
		Left = i;
		int j=i;
		while(L->Data[j+1]>L->Data[j])
		{
			Right =j+1;
			j++;
			if(j==L->Last) break;
		}
		if(Right-Left+1>max_r-max_l+1)
		{
			max_l = Left;
			max_r = Right;
		}
	}
	Print(L, max_l, max_r);
}

List ReadInput()
{
	List L = (List)malloc(sizeof(struct LNode));
	scanf("%d",&L->Last);
	L->Last--;
	int i;
	for(i=0;i<=L->Last;i++)
	{
		scanf("%d",&L->Data[i]);
		
	}
	return L;
}

void Print(List L, ElementType Left, ElementType Right)
{
	int i;
	for(i=Left;i<=Right;i++)
	{
		if(i==Left) printf("%d",L->Data[i]);
		else printf(" %d",L->Data[i]);
	}
	free(L);
}
