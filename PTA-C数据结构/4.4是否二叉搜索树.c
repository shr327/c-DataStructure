#include<stdio.h>
#include<stdlib.h>

#define NoInfo 0 /*用0表示没有结点*/ 

typedef int ElementType;
typedef int Position;
typedef struct QNode* Queue; 
typedef struct TNode* BinTree;
typedef enum{false, true} bool;

struct QNode{
	BinTree *Data;
	Position Front, Rear;
	int MaxSize;
};

struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

Queue CreateQueue(int MaxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (BinTree*)malloc(MaxSize*sizeof(BinTree));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

bool IsFull(Queue Q)
{
	return ((Q->Rear+1)%Q->MaxSize==Q->Front);
}

bool IsEmpty(Queue Q)
{
	return Q->Front == Q->Rear;
}

bool AddQ(Queue Q, BinTree X)
{
	if(IsFull(Q))
	{
		printf("队列满"); 
		return false;
	}
	else
	{
		Q->Rear = (Q->Rear+1)%(Q->MaxSize);
		Q->Data[Q->Rear] = X;
		return true;
	}
}

BinTree DeleteQ(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("队列空");
		return NULL;
	}
	else
	{
		Q->Front = (Q->Front+1)%(Q->MaxSize);
		return Q->Data[Q->Front];
	}
}

BinTree CreateBinTree()
{
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreateQueue(100);/*创建空队列*/
	/*建立第1个结点，即根节点*/ 
	scanf("%d",&Data);
	if(Data!=NoInfo)
	{
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ(Q, BT);
	}
	else return NULL;/*若第1个数据就是0，返回空树*/ 
	while(!IsEmpty(Q))
	{
		T = DeleteQ(Q);
		scanf("%d",&Data);
		if(Data==NoInfo) T->Left = NULL;
		else
		{
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ(Q, T->Left);
		}
		scanf("%d",&Data);
		if(Data==NoInfo) T->Right = NULL;
		else
		{
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ(Q, T->Right);
		}
	}
	return BT;
}

void PrintBinTree(BinTree BT)
{
	if(BT)
	{
		printf(" %d",BT->Data);
		PrintBinTree(BT->Left);
		PrintBinTree(BT->Right);	
	}
}

bool IsBST(BinTree T)
{
	if(!T) return true;
	bool Left_flag = false;
	bool Right_flag = false;
	if(IsBST(T->Left)) Left_flag = true;
	if(IsBST(T->Right)) Right_flag = true;
	if(Left_flag&&Right_flag)
	{
		if(!T->Left&&!T->Right) 
		{
			return true;
		}
		else if(!T->Left&&T->Right->Data>T->Data) 
		{
			return true;
		}
		else if(!T->Right&&T->Left->Data<T->Data)
		{
			return true;
		} 
		else if(T->Right->Data>T->Data&&T->Left->Data<T->Data) 
		{
			return true;
		}
		else return false;
	}
	else return false;
}

bool Is_BST(BinTree T,int *min, int *max)
{
	int lmin, lmax, rmin, rmax;
	if(!T) return true;
	if(!T->Left&&!T->Right)
	{
		*min = *max = T->Data;
		return true;
	}
	bool Left_flag = false;
	bool Right_flag = false;
	if((T->Left&&Is_BST(T->Left,&lmin, &lmax)&&T->Data>lmax)||!T->Left) Left_flag = true;
	if((T->Right&&Is_BST(T->Right,&rmin,&rmax)&&T->Data<rmin)||!T->Right) Right_flag = true;
	if(Left_flag&&Right_flag)
	{
		if(T->Left) *min = lmin;
		else *min = T->Data;
		if(T->Right) *max = rmax;
		else *max = T->Data;
		return true;
	}
	else return false;
}

int main()
{
	BinTree BT;
	BT = CreateBinTree();
	printf("preorder:");
	PrintBinTree(BT);
	printf("\n");
	int max = -1, min = -1;
	printf("%d",Is_BST(BT,&max,&min));
	return 0;
}



