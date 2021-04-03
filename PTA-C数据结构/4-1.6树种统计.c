#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 100000
#define MAXS 30

typedef struct TNode* BinTree;
struct TNode{
	char Data[MAXS+1];
	int Cnt;
	BinTree Left;
	BinTree Right;
};

BinTree Insert(BinTree T,char *Name)
{
	int cmp;
	if(!T)
	{
		T = (BinTree)malloc(sizeof(struct TNode));
		T->Cnt = 1;
		strcpy(T->Data, Name);
		T->Left = T->Right = NULL;
	}
	else
	{
		cmp = strcmp(Name, T->Data);
		if(cmp<0) T->Left = Insert(T->Left, Name);
		else if(cmp>0) T->Right = Insert(T->Right, Name);
		else T->Cnt++;
	}
	return T;
}

void Output(BinTree T, int N)
{
	if(!T) return;
	Output(T->Left, N);
	printf("%s %.4lf%c\n",T->Data, (double)T->Cnt/(double)N*100.0,'%');
	Output(T->Right, N);
}

int main()
{
	int N,i;
	char Name[MAXS+1];
	BinTree T = NULL;
	scanf("%d\n",&N);
	for(i=0;i<N;i++)
	{
		gets(Name);
		T = Insert(T, Name);
	}
	Output(T, N);
	return 0;
}

