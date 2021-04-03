#include<stdio.h>
#include<stdlib.h>

typedef struct TNode* BinTree;
typedef enum{false, true} bool;

struct TNode{
	int Data;
	BinTree Left;
	BinTree Right;
};

bool Is_BST(BinTree T, int* min, int* max)
{
	if(!T) return true;
	if(T->Left==NULL&&T->Right==NULL)
	{
		*min = *max = T->Data;
		return true;
	}
	
	if(T->Left&&T->Right==NULL)
	{
		if(Is_BST(T->Left, min,max)&&T->Data>*max)
		{
			*max = T->Data;
			return true;
		}
		else return false;
	}
	if(T->Left==NULL&&T->Right)
	{
		if(Is_BST(T->Right, min,max)&&T->Data<*min)
		{
			*min = T->Data;
			return true;
		}
		else return false;
		
	}
	if(T->Left&&T->Right)
	{
		return (Is_BST(T->Left, min,max)&&T->Data>*max&&Is_BST(T->Right,min,max)&&T->Data<*min);
	}
}

bool IsBST(BinTree T)
{
	int max=-1, min=-1;
	if(Is_BST(T,&min,&max)) return true;
	else return false;
}

int main()
{
	return 0;
}
