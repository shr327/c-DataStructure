#include<stdio.h>
#include<stdlib.h>

#define MaxN 100
#define Null -1

typedef int Tree;
typedef struct QNode* Queue;
typedef enum{false, true} bool;

struct QNode{
	int Data[MaxN];
	int Front;
	int Rear;
};

struct TNode{
	Tree Left;
	Tree Right;
}T1[MaxN];

int check[MaxN], N;

Tree BuildTree(struct TNode T[])
{
	int i;
	Tree Root = Null;
	char cl,cr;
	scanf("%d",&N);
	if(N)
	{
		for(i=0;i<N;i++) check[i] = 0;
		for(i=0;i<N;i++)
		{
			scanf("\n %c %c",&cl, &cr);
			if(cl!='-')
			{
				T[i].Left = cl-'0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;
			if(cr!='-')
			{
				T[i].Right = cr-'0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}
		i=0;
		while(check[i]!=0) i++;
		Root = i;
	}
	return Root;
}

Queue CreateQ()
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = 0;
	return Q;
}

bool IsFull(Queue Q)
{
	return Q->Front == (Q->Rear+1)%MaxN;
}

bool IsEmpty(Queue Q)
{
	return Q->Front==Q->Rear; 
}

bool AddQ(Queue Q, int X)
{
	if(IsFull(Q)) return false;
	Q->Data[++Q->Rear%MaxN] = X;
	return true; 
}

int DeleteQ(Queue Q)
{
	if(IsEmpty(Q)) return false;
	return Q->Data[(++Q->Front)%MaxN];
}

void Find(Tree R)
{
	int count=0;
	Queue Q = CreateQ();
	AddQ(Q,R);
	while(!IsEmpty(Q))
	{
		R = DeleteQ(Q);
		if(T1[R].Left==Null&&T1[R].Right==Null)
		{
			if(count==0)
			{
				printf("%d",R);
				count++;
			}
			else printf(" %d",R);
		}
		if(T1[R].Left!=Null) AddQ(Q, T1[R].Left);
		if(T1[R].Right!=Null) AddQ(Q, T1[R].Right);
	}
}


int main()
{
	Tree R1 = BuildTree(T1);
	Find(R1);
	
	return 0;
}
