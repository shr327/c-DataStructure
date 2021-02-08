#include<stdio.h>
#include<stdlib.h>


typedef int ElementType;
typedef struct Node *List;

struct Node{
	ElementType Data;
	List Next;
};

List Read();
void Print(List head);
List Merge(List L1, List L2);

int main()
{
	List L1,L2,L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

List Read(){
	ElementType n, i;
	List head = (List)malloc(sizeof(struct Node));
	List p=head;
	head->Next = NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		List L = (List)malloc(sizeof(struct Node));
		L->Next = NULL;
		scanf("%d",&L->Data);
		p->Next = L;
		p=L;
	}
	return head;
}

void Print(List head){
	if(!head->Next)
	{
		printf("NULL\n");
		free(head);
	}
	else
	{
		List p = head->Next;
		free(head);
		printf("%d",p->Data);
		List q=p;
		p=q->Next;
		free(q);
		while(p)
		{
			printf(" %d",p->Data);
			q = p;
			p = q->Next;
			free(q);
		}
		printf("\n");
	}
}

List Merge(List L1, List L2){
	if(L1->Next==NULL &&L2->Next!=NULL)
	{
		return L2;
	}
	if(L2->Next==NULL &&L1->Next!=NULL)
	{
		return L1;
	}
	if(L1->Next==NULL &&L2->Next==NULL)
	{
		return L2;
	}
	
	List head = (List)malloc(sizeof(struct Node));
	head->Next = NULL;
	List p1,p2,p3;
	p1 = L1->Next;
	p2 = L2->Next;
	p3 = head;
	while(p1&&p2)
	{
		if(p1->Data<=p2->Data)
		{
			p3->Next = p1;
			p3 = p1;
			p1 = p1->Next;
		}
		else
		{
			p3->Next = p2;
			p3 = p2;
			p2 = p2->Next;
		}
	}
	p3->Next = p1? p1:p2;
	L1->Next = NULL;
	L2->Next = NULL;
	return head;
}

