#include<stdio.h>
#include<stdlib.h>

#define MIN -10000
#define MaxSize 10000
#define ERROR NULL

typedef enum{false, true} bool;
typedef struct HNode* MinHeap;
typedef struct HTNode* HuffmanTree;
typedef HuffmanTree ElementType;
struct HTNode{ //哈夫曼树是带权二叉树 
	HuffmanTree Left;
	HuffmanTree Right;
	int Weight;
};

struct HNode{ //堆是完全二叉树数组 
	ElementType* Data;
	int Capacity;
	int Size;
};

bool IsFull(MinHeap H)
{
	return H->Size==H->Capacity;
}

bool Insert(MinHeap H, ElementType X)
{
	if(IsFull(H)) return false;
	H->Data[++H->Size] = X;
	int i=H->Size;
	for(;H->Data[i/2]->Weight>X->Weight;i/=2) H->Data[i] = H->Data[i/2];
	H->Data[i] = X;
	return true;
}

bool IsEmpty(MinHeap H)
{
	return H->Size==0;
}

ElementType DeleteMin(MinHeap H)
{
	if(IsEmpty(H)) return ERROR;
	ElementType min = H->Data[1];
	ElementType X = H->Data[H->Size--];
	int parent, child;
	for(parent=1;2*parent<=H->Size;parent=child)
	{
		child = 2*parent;
		if(H->Size>child&&H->Data[child+1]->Weight<H->Data[child]->Weight) child++;
		if(H->Data[child]->Weight<X->Weight) H->Data[parent] = H->Data[child];
		else break;
	}
	H->Data[parent] = X;
	return min;
}

MinHeap CreateHeap()
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Capacity = MaxSize;
	H->Size = 0;
	H->Data = (ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
	H->Data[0] = (ElementType)malloc(sizeof(struct HTNode));
	H->Data[0]->Left = H->Data[0]->Right = NULL;
	H->Data[0]->Weight = MIN;
	return H;
}

HuffmanTree Huffman(MinHeap H, int* ans)
{
	int i, N;
	HuffmanTree T;
	N = H->Size;
	for(i=1;i<N;i++)
	{
		T = (HuffmanTree)malloc(sizeof(struct HTNode));
		T->Left = DeleteMin(H);
		T->Right = DeleteMin(H);
		T->Weight = T->Left->Weight+T->Right->Weight;
		*ans += T->Weight;
		Insert(H, T);
	}
	return DeleteMin(H);
}

int main()
{
	MinHeap H = CreateHeap();
	int N, i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		ElementType X = (ElementType)malloc(sizeof(struct HTNode));
		X->Left = X->Right = NULL;
		scanf("%d",&X->Weight);
		Insert(H, X);
	}
	int ans = 0;
	HuffmanTree T = Huffman(H,&ans);
	printf("%d",ans);
	return 0;
}


