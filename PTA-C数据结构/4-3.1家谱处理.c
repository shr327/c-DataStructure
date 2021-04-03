#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

typedef enum{false, true} bool;
typedef struct TNode *Tree;

struct TNode{
	char Name[12]; //Ãû×Ö
	Tree Child;
	Tree Sibling;
};

void Insert(Tree T, char s[][71], int N);
Tree Find(Tree T, char s[]);
bool CheckParent(Tree T1, char name[]);
bool CheckSibling(Tree T1, Tree T2);
bool CheckAncestor(Tree T1, char name[]);
bool Check(Tree T, char command[][30]);

int main()
{
	int i, j, N, M;
	scanf("%d %d\n",&N, &M);
	char s[N][71];
	gets(s[0]);
	Tree T = (Tree)malloc(sizeof(struct TNode));
	strcpy(T->Name, s[0]);
	T->Child = T->Sibling = NULL;
	for(i=1;i<N;i++)
	{
		gets(s[i]);
	}
	Insert(T, s, N);
	char command[3][30], useless[3][5];
	for(i=0;i<M;i++)
	{
		scanf("%s%s%s%s%s%s",command[0],useless[0],useless[1],command[1],useless[2],command[2]);
		if(Check(T,command)) printf("True\n");
		else printf("False\n");
	}
	return 0;
}

void Insert(Tree T, char s[][71], int N)
{
	int count, tag, level, top;
	char *p;
	Tree TT, Stack[N];
	Stack[0] = T;
	level = top = 0;
	for(count=1;count<N;count++)
	{
		p = s[count] + 2*level;
		if(*p==' ')
		{
			tag=1; //½øÕ» 
			p += 2;
			level++;
		}
		else
		{
			tag = 0;
			while(*(p-1)!=' ')
			{
				p = p-2;
				level--;
				top--; 
			}
		}
		TT = (Tree)malloc(sizeof(struct TNode));
		strcpy(TT->Name, p);
		TT->Child = TT->Sibling = NULL;
		if(tag)
		{
			T = Stack[top];
			T->Child = TT;
		}
		else
		{
			T = Stack[top--];
			T->Sibling = TT;
		}
		Stack[++top] = TT;
	}
}

Tree Find(Tree T, char s[])
{
	if(T)
	{
		if(!strcmp(T->Name,s)) return T;
		if(Find(T->Child, s)) return Find(T->Child, s);
		return Find(T->Sibling, s);
	}
	return NULL;
}

bool CheckParent(Tree T1, char name[])
{
	T1 = T1->Child;
	while(T1)
	{
		if(!strcmp(T1->Name,name)) return true;
		T1 = T1->Sibling;
	}
	return false;
}

bool CheckSibling(Tree T1, Tree T2)
{
	Tree T = T1->Sibling;
	while(T)
	{
		if(T==T2) return true;
		T = T->Sibling;
	}
	T = T2->Sibling;
	while(T)
	{
		if(T==T1) return true;
		T = T->Sibling;
	}
	return false;
}

bool CheckAncestor(Tree T1, char name[])
{
	if(!T1) return false;
	if(!strcmp(T1->Name,name)) return true;
	return CheckAncestor(T1->Child,name)||CheckAncestor(T1->Sibling, name);
}

bool Check(Tree T, char command[][30])
{
	if(!strcmp(command[1], "child")) return CheckParent(Find(T, command[2]), command[0]);
	if(!strcmp(command[1], "parent")) return CheckParent(Find(T, command[0]), command[2]);
	if(!strcmp(command[1], "sibling")) return CheckSibling(Find(T, command[0]),Find(T, command[2]));
	if(!strcmp(command[1], "ancestor")) return CheckAncestor(Find(T,command[0])->Child, command[2]);
	if(!strcmp(command[1], "descendant")) return CheckAncestor(Find(T, command[2])->Child,command[0]);
}
