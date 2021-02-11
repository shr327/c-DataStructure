#include<stdio.h>
#include<stdlib.h>

#define ERROR -1

typedef struct Node *List;
typedef int ElementType;

struct Node{
	ElementType Data;
	List Next;
};

List Read();
void Print(List L);
ElementType Find(List L, int m);

int main()
{
	List L;
	int m;
	L = Read();
	scanf("%d",&m);
	printf("%d\n",Find(L,m));
	Print(L);
	return 0;
}

ElementType Find(List L, int m)
{
	int count=0;
	List p = L->Next;
	while(p)
	{
		count++;
		p=p->Next; 
	}
	if(count<m) return ERROR;
	
	int num = count - m +1, i=1;
	p = L->Next;
	while(i<num)
	{
		p = p->Next;
		i++;
	}
	return p->Data;
}

List Read()
{
	List head = (List)malloc(sizeof(struct Node));
	head->Next = NULL;
	int n;
	scanf("%d",&n);
	int i;
	List p=head;
	for(i=0;i<n;i++)
	{
		List node = (List)malloc(sizeof(struct Node));
		node->Next = NULL;
		scanf("%d",&node->Data);
		p->Next = node;
		p = node;
		
	}
	return head;
}

void Print(List L)
{
	List p=L->Next;
	printf("%d",p->Data);
	List q = p->Next;
	free(p);
	while(q)
	{
		printf(" %d",q->Data);
		p = q;
		free(p); 
		q = q->Next;
	}
}
