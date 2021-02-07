#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Node* List;
 
struct Node{
	ElementType Data;
	List Next;
}; 

List Read();
void Print(List L);
List Insert(List L, ElementType);

int main(){
	List L;
	ElementType X;
	L = Read();
	scanf("%d",&X);
	L = Insert(L,X);
	Print(L);
	
	return 0;
}

void Print(List L){
	L=L->Next;
	printf("%d",L->Data);
	while(L->Next!=NULL){
		L=L->Next;
		printf(" %d",L->Data);
	}
	free(L);
}

List Read(){
	ElementType i, n;
	List head = (List)malloc(sizeof(struct Node));
	head->Next = NULL;
	List p = head;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		List Node = (List)malloc(sizeof(struct Node));
		Node->Next = NULL;
		scanf("%d",&Node->Data);
		p->Next = Node;
		p = p->Next;
	}
	return head;
}



List Insert( List L, ElementType X ){
    List p=L;
    List n=(List)malloc(sizeof(struct Node));
    n->Data=X;
    n->Next = NULL;
    while(L->Next!=NULL){
        if(X<L->Next->Data){
            n->Next=L->Next;
            L->Next=n;
            return p;
        }
        L=L->Next;
    }
    L->Next=n;
    return p;
}
