#include<stdio.h>
#include<stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef enum{push, pop, inject, eject, end} Operation;
typedef enum{false, true} bool;
typedef int Position;
typedef struct QNode* Deque;
struct QNode{
	ElementType *Data;
	Position Front, Rear;
	int MaxSize;
};

Deque CreateDeque(int MaxSize)
{
	Deque D = (Deque)malloc(sizeof(struct QNode));
	MaxSize++;
	D->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	D->Front = D->Rear = 0;
	D->MaxSize = MaxSize;
	return D;
}

bool Push( ElementType X, Deque D )//将元素X插入到双端队列D的头；
{
    if((D->Rear + 1) % D->MaxSize == D->Front)//队列满
    {
        return false;
    }
    D->Front = (D->Front + D->MaxSize - 1) % D->MaxSize;//头指针前移
    D->Data[D->Front] = X;//插入数据
    return true;
    

}
ElementType Pop( Deque D )//删除双端队列D的头元素，并返回；
{
   if(D->Rear == D->Front)//队列空
   {
       return ERROR;
   }
	ElementType n = D->Data[D->Front];//暂存数据
    D->Front = (D->Front + 1) % D->MaxSize;//头指针后移
    return n;
        
    
}
bool Inject( ElementType X, Deque D )//将元素X插入到双端队列D的尾部
{
   if((D->Rear + 1) % D->MaxSize == D->Front)//队列满
    {
        return false;
    }
    D->Data[D->Rear] = X;//插入X
    D->Rear = (D->Rear + 1) % D->MaxSize;//尾指针后移 
    return true;
    
}
ElementType Eject( Deque D )//删除双端队列D的尾部元素，并返回
{
    if(D->Rear == D->Front)//队列空
   {
       return ERROR;
   }
   else
   {
    D->Rear = (D->Rear + D->MaxSize-1 ) % D->MaxSize;//尾指针前移
    return  D->Data[D->Rear];//返回值
   }
}

Operation GetOp()
{
	char s[10];
	scanf("%s",s);
	if(strcmp(s,"Push")==0) return push;
	else if(strcmp(s,"Pop")==0) return pop;
	else if(strcmp(s,"Inject")==0) return inject;
	else if(strcmp(s,"Eject")==0) return eject;
	else if(strcmp(s,"End")==0) return end;
}

void PrintDeque( Deque D )
{
	printf("Inside Deque:");
	Position i = D->Front;
	while(1)
	{
		printf(" %d",D->Data[i]);
		if((i+1)%D->MaxSize==D->Rear) break;
		i = (i+1)%D->MaxSize;
	}
	printf("\n");
}

int main()
{
	ElementType X;
	Deque D;
	int N, done = 0;
	scanf("%d", &N);
	D = CreateDeque(N);
	while(!done)
	{
		switch(GetOp())
		{
			case push:
				scanf("%d",&X);
				if(!Push(X,D)) printf("Deque is Full!\n");
				break;
			case pop:
				X = Pop(D);
				if(X==ERROR) printf("Deque is Empty!\n");
				else printf("%d is out\n",X);
				break;
			case inject:
				scanf("%d", &X);
				if(!Inject(X, D)) printf("Deque is Full!\n");
				break;
			case eject:
				X = Eject(D);
				if(X == ERROR) printf("Deque is Empty!\n");
				else printf("%d is out\n",X);
				break;
			case end:
				PrintDeque(D);
				done = 1;
				break;
		}
	}
	return 0;
}




