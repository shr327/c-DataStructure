#include <stdio.h>
#include <stdlib.h>

#define MAXS 101
#define MAXN 50

typedef enum{false, true} bool;
typedef int ElementType;

/*-----��ջ�Ķ���-----*/
typedef int Position;
typedef struct SNode *Stack;
struct SNode{
	ElementType *Data;
	Position Top;
	int MaxSize;
};

Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
bool Push(Stack S, ElementType X);
bool Pop(Stack S);
void Clear(Stack S);
/*-----��ջ�Ķ������-----*/

int main()
{
	int M, N, i, j;
	char Str[MAXS];
	Stack S;
	scanf("%d %d\n",&N, &M);
	S = CreateStack(M);
	for(i=0; i<N; i++)
	{
		scanf("%s",Str);
		Clear(S);
		for(j=0;Str[j]!='\0';j++)
		{
			if((Str[j]=='S')&&(!Push(S,1))) break;
			if((Str[j]=='X')&&(!Pop(S))) break;
		}
		if((Str[j]=='\0')&&IsEmpty(S)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsEmpty(Stack S)
{
	return (S->Top == -1);
}

bool IsFull(Stack S)
{
	return (S->Top == (S->MaxSize-1));
}

bool Push(Stack S, ElementType X)
{
	if(IsFull(S)) return false;
	else
	{
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool Pop(Stack S)
{
	if(IsEmpty(S)) return false;
	else
	{
		(S->Top)--;
		 return true;
	}
}

void Clear(Stack S)
{
	while(!IsEmpty(S)) Pop(S);
}

