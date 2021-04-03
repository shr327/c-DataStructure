#include<stdio.h>
#include<stdlib.h>

#define Swap(a, b) a^=b, b^=a, a^=b;
#define MAXSIZE 1001

typedef int ElementType;
typedef int Position;
typedef struct LNode* List;
typedef List Tree;

struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
};
 
int NCA(int a, int b)
{
	while(a!=b)
	{
		if(a>b) Swap(a, b);
		while(b>a) b/=2;
	}
	return a;
}

int main()
{
	Tree T = (Tree)malloc(sizeof(struct LNode));
	T->Last = 0;
	T->Data[0] = 0;
	int i, N;
	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&T->Data[i]);
	int a, b;
	scanf("%d %d",&a, &b);
	if(!T->Data[a]) printf("ERROR:T[%d]is NULL",a);
	else if(!T->Data[b]) printf("ERROR:T[%d]is NULL",b);
	else
	{
		printf("%d %d",NCA(a, b),T->Data[NCA(a, b)]);
	}
	return 0;
}


