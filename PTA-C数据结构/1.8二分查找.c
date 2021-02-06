#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput(){
	List L;
	ElementType i;
	scanf("%d",&L->Last);
	for(i=1;i<=L->Last;i++){
		scanf("%d",&L->Data[i]);
	}
	return L;
}

Position BinarySearch(List L, ElementType X){
	int left=1, right = L->Last;
	int mid;
	while(left<=right){
		mid = (left+right)/2;
		if(L->Data[mid] < X) left = mid +1;
		else if(L->Data[mid]==X) return mid;
		else right=mid-1;
	}
	return NotFound;
}

