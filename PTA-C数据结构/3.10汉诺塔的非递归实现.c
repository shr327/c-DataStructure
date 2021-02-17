#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef enum{false, true} bool;

typedef struct{
	int N;
	char A;
	char B;
	char C;
} ElementType; /*汉诺塔问题结构类型*/

/*-----堆栈的定义-----*/
typedef int Position;
typedef struct SNode *Stack;
struct SNode{
	ElementType *Data;
	Position Top;
	int MaxSize;
};

Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
void Push(Stack S, ElementType X);
ElementType Pop(Stack S);
/*-----堆栈的定义结束-----*/

void Hanoi(int n) /*借助堆栈的非递归实现*/
{
	Stack S;
	ElementType P, toPush;
	S = CreateStack(MAXSIZE);
	P.N = n; P.A = 'a'; P.B = 'b'; P.C = 'c';
	Push(S, P); /*将初始问题(n,a,b,c)放入堆栈*/
	while(!IsEmpty(S))
	{
		P = Pop(S);
		if(P.N == 1)
		{
			printf("%c -> %c\n",P.A, P.C);
		}
		else
		{
			toPush.N = P.N-1;
			toPush.A = P.B; toPush.B = P.A; toPush.C = P.C;
			Push(S, toPush);
			toPush.N = 1;
			toPush.A = P.A; toPush.B = P.B; toPush.C = P.C;
			Push(S, toPush);
			toPush.N = P.N-1;
			toPush.A = P.A; toPush.B = P.C; toPush.C = P.B;
			Push(S, toPush);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	Hanoi(n);
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

void Push(Stack S, ElementType X)
{
	S->Data[++(S->Top)] = X;
}

ElementType Pop(Stack S)
{
	return (S->Data[(S->Top)--]);
}


