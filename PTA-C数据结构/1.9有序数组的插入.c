#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );
	free(L);
    return 0;
}
List ReadInput(){
	List L = (List)malloc(sizeof(struct LNode));
	ElementType i; 
	scanf("%d",&L->Last);
	L->Last-=1;
	for(i=0;i<=L->Last;i++){
		scanf("%d",&L->Data[i]);
	} 
	return L;
}

void PrintList( List L ){
	int i;
	for(i=0;i<=L->Last;i++){
		printf("%d ",L->Data[i]);
	}
}


bool Insert(List L, ElementType X){
	ElementType i, j;
	if(L->Last == MAXSIZE-1) return false;
	
	if(L->Data[L->Last]>X){
		L->Data[L->Last+1]=X;
		L->Last++;
		return true;
	}
	if(L->Data[0]<X){
		for(j=L->Last;j>=0;j--){
			L->Data[j+1]=L->Data[j];
		}
		L->Data[0] = X;
		L->Last++;
		return true;
	}
	for(i=0;i<=L->Last;i++){
		if(L->Data[i]==X) return false;
		
		if(L->Data[i] > X && L->Data[i+1] < X){
			for(j=L->Last;j>i;j--){
				L->Data[j+1]=L->Data[j];
			}
			L->Data[i+1] = X;
			L->Last++;
			return true;
		}
	}
	
}

