#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct LNode *List;

List Move();
void PrintList( List L );


struct LNode{
	int Data[MAX];
	int Last;
};

int main(){
	List L;
	L = Move();
	PrintList(L);
	free(L);
	return 0;
}

List Move(){
	List L=(List)malloc(sizeof(struct LNode));
	int b;
	scanf("%d",&L->Last);
	scanf("%d",&b);
	int i;
	L->Last=L->Last-1;
	if(b>L->Last){
		b=b%(L->Last+1);
	}
	
	
	for(i=0;i<=L->Last;i++){
		scanf("%d",&L->Data[i]);
	}

	List L1 = (List)malloc(sizeof(struct LNode));
	L1->Last=L->Last;
	for(i=0;i<L->Last-b+1;i++){
		L1->Data[i]=L->Data[i+b];
	}
	for(i=0;i<b;i++){
		L1->Data[L->Last-b+i+1] = L->Data[i];
	}

	free(L);
	return L1;
}


void PrintList(List L){
	int i;
	for(i=0;i<=L->Last;i++){
		if(i==0){
			printf("%d",L->Data[i]);
		}
		else printf(" %d",L->Data[i]);
	}
}
