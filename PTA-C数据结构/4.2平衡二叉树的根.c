#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct AVLNode *AVLTree;

struct AVLNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int H;
}; 

int Max(int a, int b)
{
	return a>b?a:b;
}

int GetH(AVLTree T);
AVLTree LL(AVLTree A);
AVLTree RR(AVLTree A);
AVLTree LR(AVLTree A);
AVLTree RL(AVLTree A);
AVLTree Insert(AVLTree T, ElementType X);

int main()
{
	int N, K, i;
	AVLTree T = NULL;
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		scanf("%d",&K);
		T = Insert(T, K);
	}
	printf("%d\n", T->Data);
	return 0;
}

int GetH(AVLTree T)
{
	if(T) return T->H;
	else return -1;
} 

AVLTree LL(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->H = Max(GetH(A->Left),GetH(A->Right))+1; 
	B->H = Max(GetH(B->Left),GetH(B->Right))+1; 
	return B;
}

AVLTree RR(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->H = Max(GetH(A->Left),GetH(A->Right))+1; 
	B->H = Max(GetH(B->Left),GetH(B->Right))+1; 
	return B;
}

AVLTree LR(AVLTree A)
{
	A->Left = RR(A->Left);
	return LL(A);
}

AVLTree RL(AVLTree A)
{
	A->Right = LL(A->Right);
	return RR(A); 
}

AVLTree Insert(AVLTree T, ElementType X)
{
	if(!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->H = 0;
		T->Data = X;
		T->Left = T->Right = NULL;
	}
	else if(X<T->Data)
	{
		T->Left = Insert(T->Left, X);
		if(GetH(T->Left) - GetH(T->Right)==2)
		{
			if(X<T->Left->Data) T = LL(T);
			else T = LR(T);
		}
	}
	else if(X>T->Data)
	{
		T->Right = Insert(T->Right, X);
		if(GetH(T->Left) - GetH(T->Right)==-2)
		{
			if(X>T->Right->Data) T = RR(T);
			else T = RL(T); 
		}
	}
	T->H = Max(GetH(T->Left),GetH(T->Right))+1;
	return T;
}


