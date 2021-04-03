#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN -1;
#define MAXSIZE 100001

typedef struct HNode* MinHeap;
typedef struct Node* ElementType;

struct Node{
	int data;
	char msg[20];
};

struct HNode{
	ElementType* Data;
	int Capacity;
	int Size;
};

MinHeap CreateHeap()
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Capacity = MAXSIZE;
	H->Size = 0;
	H->Data = (ElementType*)malloc(MAXSIZE*sizeof(struct Node)); //结构体指针数组指针 
	H->Data[0] = (ElementType)malloc(sizeof(struct Node)); //结构体指针
	H->Data[0]->data=MIN;
	strcpy(H->Data[0]->msg,"EMPTY QUEUE!");
	return H;
}

void Insert(MinHeap H, ElementType X)
{
	H->Data[++H->Size] = X;
	int i = H->Size;
	for(;H->Data[i/2]->data > X->data;i/=2)
	{
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = X;
}

void DeleteMin(MinHeap H)
{
	if(H->Size==0)
	{
		printf("%s\n",H->Data[0]->msg);
		return ;
	}
	ElementType Min = H->Data[1];
	ElementType X = H->Data[H->Size--];
	int parent, child;
	for(parent=1;parent*2<=H->Size;parent=child)
	{
		child = parent*2;
		if(H->Size>child&&H->Data[child+1]->data<H->Data[child]->data) child++;
		if(H->Data[child]->data < X->data) H->Data[parent] = H->Data[child];
		else break;
	}
	H->Data[parent] = X;
	printf("%s\n",Min->msg);
}

int main()
{
	MinHeap H = CreateHeap();
	int i, N, data;
	char order[5];
	char msg[20];
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%s",order);
		if(!strcmp(order, "PUT"))
		{
			scanf("%s %d",msg, &data); 
			ElementType X = (ElementType)malloc(sizeof(struct Node)); //结构体指针 
			X->data = data;
			strcpy(X->msg, msg);
			Insert(H, X);
		}
		else
		{
			DeleteMin(H);
		}
	}
	return 0;
}
