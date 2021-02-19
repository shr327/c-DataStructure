#include<stdio.h>
#include<stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef enum{push, pop, end} Operation;
typedef enum{false, true} bool;
typedef struct SNode* Stack;

struct SNode{
	ElementType* Data;
	Position Top;
	int MaxSize;
};

Stack CreateStack(int MaxSize)
{
	
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->MaxSize = MaxSize;
	S->Top = 0; 
	return S;
}

bool Push(Stack S, ElementType X)
{
	if(S->Top==S->MaxSize)
	{
		printf("Stack Full\n");
		return false;
	}
	S->Data[S->Top++] = X;
	return true;
}

ElementType Pop(Stack S)
{
	if(S->Top==0)
	{
		printf("Stack Empty\n");
		return ERROR;
	}
	return S->Data[--S->Top];
} 

Operation GetOp()
{
	char s[5];
	scanf("%s",s);
	if(strcmp(s,"Push")==0) return push;
	else if(strcmp(s,"Pop")==0) return pop;
	else if(strcmp(s,"End")==0) return end;
}

void PrintStack(Stack S)
{
	printf("%d",S->Data[--S->Top]);
	while(S->Top)
	{
		printf(" %d",Pop(S));
	}
}

int main()
{
	ElementType X;
	Stack S;
	int N, done = 0;
	
	scanf("%d",&N);
	S = CreateStack(N);
	while(!done)
	{
		switch(GetOp())
		{
			case push:
				scanf("%d",&X);
				Push(S, X);
				break;
			case pop:
				X = Pop(S);
				if(X!=ERROR) printf("%d is out\n",X);
				break;
			case end:
				PrintStack(S);
				done = 1;
				break;
		}
	}
	return 0;
}
