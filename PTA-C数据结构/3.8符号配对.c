#include<stdio.h>
#include<stdlib.h>

#define MAXN 100
typedef enum{false, true} bool;
typedef enum{ret, lc, lbrc, lbrkt, lpr, rc, rbrc, rbrkt, rpr, others} Token;
typedef Token ElementType;

/*----------��ջ����----------*/
typedef int Position;
typedef struct SNode *Stack;

struct SNode{
	ElementType *Data;
	Position Top;
	int MaxSize;
};

Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
void Push(Stack S, ElementType X);
ElementType Peek(Stack S);
void Pop(Stack S);
/*----------��ջ�������----------*/

bool IsEnd(int newline, char *c);
Token GetToken(char c);
bool IsPaired(Token t1, Token t2);
void PrintS(Token t);
int Check(Token *T1, Token *T2);

int main()
{
	Token T1, T2;
	int error = Check(&T1, &T2);
	if(!error) printf("YES\n");
	else
	{
		printf("NO\n");
		switch(error)
		{
			case 1:printf("?-");PrintS(T1);break;
			case 2:PrintS(T2);printf("-?");break;
			default:break; 
		}
		printf("\n");
	}
	return 0;
}

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsEmpty(Stack S)
{
	return (S->Top==-1);
}

void Push(Stack S, ElementType X)
{
	S->Data[++(S->Top)] = X;
}

ElementType Peek(Stack S)
{
	return (S->Data[S->Top]);
}

void Pop(Stack S)
{
	(S->Top)--;
}

int Check(Token *T1, Token *T2)
{
	Stack S; /*���ƥ���õĶ�ջ*/
	char c; /*c�������ַ�*/ 
	Token t; /*���ַ�ת���������*/ 
	int newline, error; /* newline��ʶ��ǰ�Ƿ����У�error��ʾ���� */
	S = CreateStack(MAXN);
	newline = 1; error = 0; /* ��ʼΪ���У�û�д��� */
	while(1)
	{
		scanf("%c",&c);
		if(IsEnd(newline, &c)) break; /* ����Ѿ�������β��������ѭ�� */
		else
		{
			switch(t = GetToken(c))
			{
				case lc:
				case lbrc:
				case lbrkt:
				case lpr:
					Push(S, t); newline = 0; break;
				case rc:
				case rbrc:
				case rbrkt:
				case rpr:
					/*����ջ�ѿգ��Ұ����ƥ��*/
					if(IsEmpty(S)) error = 1;
					/*��ջ��Ԫ�غ͵�ǰ���벻ƥ�䣬������ƥ��*/ 
					else if(!IsPaired(t,Peek(S))) error = 2;
					else Pop(S);/*һ����������ȥһ��*/
					newline = 0;/*����������*/ 
					break;
				case ret: newline = 1; break;/*�����س����ʶ����*/
				default: newline = 0;break;/*�����ַ�����������*/ 
			}
			if(error) break;/*������ִ���������ѭ��*/ 
		}
	}
	/* ������βʱ��ջ��û�գ������ж� */
	if(!error && !IsEmpty(S)) error = 2;
	(*T1) = t, (*T2) = Peek(S);
	return error; 
}

bool IsEnd(int newline, char *c)
{
	if(newline && (*c)=='.')
	{
		scanf("%c",c);
		if((*c)=='\n') return true;
		else return false;
	}
	else return false;
}

Token GetToken(char c)
{
	switch(c)
	{
		case'\n':return ret;
		case'{':return lbrc;
		case'[':return lbrkt;
		case'(':return lpr;
		case'/':
			scanf("%c",&c);
			if(c=='*') return lc;
			else return GetToken(c);
		case'}':return rbrc;
		case']':return rbrkt;
		case')':return rpr;
		case'*':
			scanf("%c",&c);
			if(c=='/') return rc;
			else return GetToken(c); 
		default: return others;
	}
}

bool IsPaired(Token t1, Token t2)
{
	return (t1-t2)==4;
}

void PrintS(Token t)
{
	switch(t)
	{
		case lc:printf("/*");break;
		case lbrc:printf("{");break;
		case lbrkt:printf("[");break;
		case lpr:printf("(");break;
		case rc:printf("*/");break;
		case rbrc:printf("}");break;
		case rbrkt:printf("]");break;
		case rpr:printf(")");break;
		default:break;
	}
}


