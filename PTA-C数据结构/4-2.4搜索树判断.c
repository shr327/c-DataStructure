#include<stdio.h>
#include<stdlib.h>

#define MaxN 10000

typedef struct TNode* BinTree;
typedef enum{false, true} bool;

struct TNode{
	BinTree Left;
	BinTree Right;
	int Data;
};

int Inorder1[MaxN], Inorder2[MaxN];
int flag=0;

BinTree BuildMTreePre(int Inorder[], int Preorder[], int N)
{
	int p;
	if(!N) return NULL;
	BinTree T = (BinTree)malloc(sizeof(struct TNode));
	T->Data = Preorder[0];
	T->Left = T->Right = NULL;
	for(p=N-1;p>=0;p--) if(Inorder[p] == T->Data) break;
	if(p<0)
	{
		flag=1;
		return NULL;
	}
	T->Left = BuildMTreePre(Inorder,Preorder+1,p);
	T->Right = BuildMTreePre(Inorder+p+1,Preorder+p+1,N-p-1);
	return T;
}

BinTree BuildTreePre(int Inorder[], int Preorder[], int N)
{
	int p;
	if(!N) return NULL;
	BinTree T = (BinTree)malloc(sizeof(struct TNode));
	T->Data = Preorder[0];
	T->Left = T->Right = NULL;
	for(p=0;p<N;p++) if(Inorder[p] == T->Data) break;
	if(p==N)
	{
		flag=1;
		return NULL;
	}
	T->Left = BuildTreePre(Inorder,Preorder+1,p);
	T->Right = BuildTreePre(Inorder+p+1,Preorder+p+1,N-p-1);
	return T;
}

bool Is_BST(BinTree T, int *min, int *max) //没用 
{
	int lmin, lmax, rmin, rmax;
	if(!T) return true;
	if(!T->Left&&!T->Right)
	{
		*min = *max = T->Data;
		return true;
	}
	bool left_flag = false, right_flag = true;
	
	if(!T->Left||(T->Left&&Is_BST(T->Left, &lmin, &lmax)&&T->Data>lmax)) left_flag = true;
	if(!T->Right||(T->Right&&Is_BST(T->Right, &rmin, &rmax)&&T->Data<=rmin)) right_flag = true;
	if(left_flag&&right_flag)
	{
		if(T->Left) *min = lmin;
		else *min = T->Data;
		if(T->Right) *max = rmax;
		else *max = T->Data;
		return true;
	}
	else return false;
}

bool Is_MBST(BinTree T, int *min, int *max) //没用
{
	int lmin, lmax, rmin, rmax;
	if(!T) return true;
	if(!T->Left&&!T->Right)
	{
		*min = *max = T->Data;
		return true;
	}
	bool left_flag = false, right_flag = true;
	
	if(!T->Left||(T->Left&&Is_MBST(T->Left, &lmin, &lmax)&&T->Data<=lmin)) left_flag = true;
	if(!T->Right||(T->Right&&Is_MBST(T->Right, &rmin, &rmax)&&T->Data>rmax)) right_flag = true;
	if(left_flag&&right_flag)
	{
		if(T->Left) *max = lmax;
		else *max = T->Data;
		if(T->Right) *min = lmin;
		else *min = T->Data;
		return true;
	}
	else return false;
}

int* Upsort(int Preorder[], int N)
{
	int i, j;
	for(i=0;i<N;i++)
	{
		Inorder1[i] = Preorder[i];
	}
	
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(Inorder1[i]>Inorder1[j])
			{
				int tmp;
				tmp = Inorder1[i];
				Inorder1[i] = Inorder1[j];
				Inorder1[j] = tmp;
			}
		}
	}
	return Inorder1;
}

int* Downsort(int Preorder[], int N)
{
	int i, j;
	for(i=0;i<N;i++)
	{
		Inorder2[i] = Preorder[i];
	}
	
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(Inorder2[i]<Inorder2[j])
			{
				int tmp;
				tmp = Inorder2[i];
				Inorder2[i] = Inorder2[j];
				Inorder2[j] = tmp;
			}
		}
	}
	return Inorder2;
}

int count=0;
void PostorderTraversal(BinTree T)
{
	if(T)
	{
		PostorderTraversal(T->Left);
		PostorderTraversal(T->Right);
		count++;
		if(count==1) printf("%d",T->Data);
		else printf(" %d",T->Data);
	}
}

int main()
{
	BinTree T;
	int i, N;
	scanf("%d",&N);
	int Preorder[N], *Inorder;
	for(i=0;i<N;i++) scanf("%d",&Preorder[i]);
	if(Preorder[N-1]<Preorder[0])
	{
		int min, max;
		min = max = -1;
		Inorder = Downsort(Preorder, N);
		T = BuildMTreePre(Inorder, Preorder, N);
		
		if(flag==0)
		{
			printf("YES\n");
			PostorderTraversal(T);
		}
		else printf("NO\n");
	}
	else
	{
		int min, max;
		min = max = -1;
		Inorder = Upsort(Preorder, N);
		T = BuildTreePre(Inorder, Preorder, N);
		if(flag==0)
		{
			printf("YES\n");
			PostorderTraversal(T);
		}
		else printf("NO\n");
	}
	return 0;
}

