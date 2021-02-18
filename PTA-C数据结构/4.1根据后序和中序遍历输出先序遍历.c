#include <stdio.h>
#include <stdlib.h>

#define MAXN 30
typedef int ElementType;

typedef struct TNode *BinTree;

struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree BuildTree(int Inorder[], int Postorder[], int N);
void PreorderTraversal(BinTree BT);

int main()
{
	BinTree T;
	int Inorder[MAXN], Postorder[MAXN], N, i;
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		scanf("%d",&Postorder[i]);
	}
	for(i=0; i<N; i++)
	{
		scanf("%d",&Inorder[i]);
	}
	T = BuildTree(Inorder, Postorder, N);
	printf("Preorder:"); PreorderTraversal(T); printf("\n");
}

BinTree BuildTree(int Inorder[], int Postorder[], int N)
{
	BinTree T;
	int p;
	if(!N) return NULL;/*µÝ¹éÖÕÖ¹Ìõ¼þ£º¿ÕÊ÷*/
	T = (BinTree)malloc(sizeof(struct TNode));
	T->Data = Postorder[N-1];
	T->Left = T->Right = NULL;
	for(p=0;p<N;p++)
	{
		if(Inorder[p]==Postorder[N-1]) break;
	}
	T->Left = BuildTree(Inorder, Postorder, p);
	T->Right = BuildTree(Inorder+p+1, Postorder+p, N-p-1);
	return T;
}

void PreorderTraversal(BinTree T)
{
	if(T)
	{
		printf(" %d", T->Data);
		PreorderTraversal(T->Left);
		PreorderTraversal(T->Right);
	}
}


