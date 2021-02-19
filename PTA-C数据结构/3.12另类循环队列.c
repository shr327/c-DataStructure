#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef enum{addq, delq, end} Operation;
typedef enum{false, true} bool;

typedef int Position;
typedef struct QNode* Queue;

struct QNode{
	ElementType* Data;
	Position Front;
	int Count;
	int MaxSize;
};

Queue CreateQueue(int MaxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	Q->Front = 0;
	Q->Count = 0;
	Q->MaxSize = MaxSize;
	return Q; 
}

bool AddQ(Queue Q, ElementType X)
{
	if(Q->Count == Q->MaxSize)
	{
		printf("Queue Full\n");
		return false;
	}
	Q->Count++;
	Q->Data[(Q->Count+Q->Front)%Q->MaxSize]=X;
	return true;
}

ElementType DeleteQ(Queue Q)
{
	if(Q->Count == 0)
	{
		printf("Queue Empty\n");
		return ERROR;
	}
	Q->Count--;
	Q->Front=(Q->Front+1)%Q->MaxSize;
	return Q->Data[Q->Front];
}

Operation GetOp()
{
	char s[10];
	scanf("%s",s);
	if(strcmp(s,"Del")==0) return delq;
	else if(strcmp(s,"Add")==0) return addq;
	else if(strcmp(s,"End")==0) return end;
}

int main()
{
	ElementType X;
	Queue Q;
	int N, done = 0;
	scanf("%d",&N);
	Q = CreateQueue(N);
	while(!done)
	{
		switch(GetOp())
		{
			case addq:
				scanf("%d",&X);
				AddQ(Q, X);
				break;
			case delq:
				X = DeleteQ(Q);
				if(X!=ERROR) printf("%d is out\n",X);
				break;
			case end:
				while(Q->Count) printf("%d ",DeleteQ(Q));
				done = -1;
				break;
		}
	}
	return 0;
}
