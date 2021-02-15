#include<stdio.h>
#include<stdlib.h> 

typedef struct PolyNode *Ptr;
struct PolyNode{
	int Coef;
	int Expon;
	Ptr Next;
};

void Attach(int coef, int expon, Ptr *PtrRear)
{
	Ptr P;
	P = (Ptr)malloc(sizeof(struct PolyNode));
	P->Coef = coef;
	P->Expon = expon;
	P->Next = NULL;
	(*PtrRear)->Next = P;
	*PtrRear = P;
}

Ptr ReadPoly()
{
	Ptr P, Rear, t;
	int coef, expon, N;
	scanf("%d",&N);
	P = (Ptr)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	while(N--)
	{
		scanf("%d %d",&coef ,&expon);
		Attach(coef, expon, &Rear);
	}
	t = P; P = P->Next; free(t);
	return P;
}

void PrintPoly(Ptr P)
{
	if(!P) printf("0 0\n");
	else
	{
		printf("%d %d",P->Coef,P->Expon);
		P=P->Next;
		while(P)
		{
			printf(" %d %d",P->Coef, P->Expon);
			P = P->Next;
		}
		printf("\n");
	}
}

Ptr Mult(Ptr P1, Ptr P2)
{
	Ptr P, Rear, t1, t2, t;
	int coef, expon;
	if(!P1||!P2) return NULL;
	t1 = P1;
	t2 = P2;
	P = (Ptr)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	while(t2)
	{
		Attach(t1->Coef*t2->Coef, t1->Expon+t2->Expon,&Rear);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while(t1)
	{
		t2 = P2; Rear = P;
		while(t2)
		{
			expon = t1->Expon+t2->Expon;
			coef = t1->Coef*t2->Coef;
			while(Rear->Next&&Rear->Next->Expon>expon)
				Rear = Rear->Next;
			if(Rear->Next&&Rear->Next->Expon==expon)
			{
				if(Rear->Next->Coef + coef) Rear->Next->Coef+=coef;
				else
				{
					t = Rear->Next;
					Rear->Next = t->Next;
					free(t);
				}
			}
			else
			{
				t = (Ptr)malloc(sizeof(struct PolyNode));
				t->Coef = coef; t->Expon = expon;
				t->Next = Rear->Next;
				Rear->Next = t;
				Rear->Next = Rear->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	t = P; P=P->Next; free(t);
	return P;
}

Ptr Sum(Ptr P1, Ptr P2)
{
	Ptr P, Rear, t1, t2, t;
	P = (Ptr)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	t1 = P1;
	t2 = P2;
	while(t1&&t2)
	{
		if(t1->Expon > t2->Expon)
		{
			Attach(t1->Coef, t1->Expon, &Rear);
			t1 = t1->Next;
		}
		else if(t1->Expon==t2->Expon)
		{
			if(t1->Coef+t2->Coef==0) 
			{
				t1 = t1->Next;
				t2 = t2->Next;
			}
			else
			{
				Attach(t1->Coef+t2->Coef, t1->Expon, &Rear);
				t1 = t1->Next;
				t2 = t2->Next;
			}
		}
		else
		{
			Attach(t2->Coef, t2->Expon, &Rear);
			t2 = t2->Next;
		}
	}
	if(!t1)
	{
		while(t2)
		{
			Attach(t2->Coef, t2->Expon, &Rear);
			t2 = t2->Next;
		}
	}
	else
	{
		while(t1)
		{
			Attach(t1->Coef, t1->Expon, &Rear);
			t1 = t1->Next;
		}
	}
	t = P; P=P->Next; free(t);
	return P;
}

int main()
{
	Ptr P1, P2, P;
	P1 = ReadPoly();
	P2 = ReadPoly();
	P = Mult(P1, P2);
	PrintPoly(P);
	P = Sum(P1, P2);
	PrintPoly(P);
	return 0;
}

