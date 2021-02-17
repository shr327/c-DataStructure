#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXL 21

typedef enum{false, true} bool;
typedef char ElementType;

/*-----堆栈的定义-----*/
typedef struct SNode* Stack;
typedef int Position;
struct SNode{
	ElementType *Data;
	int MaxSize;
	Position Top;
};

Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
void Push(Stack S, ElementType X);
ElementType Peek(Stack S);
ElementType Pop(Stack S);
/*-----堆栈的定义结束-----*/ 

typedef enum{lpr, rpr, plus, minus, times, divide, eos, operand} Precedence;
bool IsSign(char *expr, int i);
char GetOp(char *expr, int *i, char* Postfix, int *j);
Precedence GetToken(char op);
void ToPostfix(char *Expr);


int main()
{
	char Str[MAXL];
	scanf("%s",Str);
	ToPostfix(Str);
	return 0;
}

void ToPostfix(char *expr)
{
	int i, j , L;
	char Postfix[2*MAXL], Op;
	Stack S;
	Precedence token;
	
	S = CreateStack(MAXL);
	L = strlen(expr);
	j = 0; /*j指向Postfix[]中当前要写入的位置*/
	for(i=0;i<L;i++)
	{
		Op = GetOp(expr, &i, Postfix, &j);
		token = GetToken(Op);
		if(token == operand) continue; /*不处理数字*/
		switch(token)
		{
			case lpr: Push(S, '(' ); break;
			case rpr: /*括号内的中缀表达式已经扫描完毕*/ 
				while(Peek(S)!='(')
				{
					Postfix[j++] = Pop(S);
					Postfix[j++] = ' ';
				}
				Pop(S);
				break;
			default:
				while(!IsEmpty(S)&&Peek(S)!='('&&token<=GetToken(Peek(S)))
				{
					Postfix[j++] = Pop(S);
					Postfix[j++] = ' ';
				}
				Push(S, Op);
				break;
		}
	}
	while(!IsEmpty(S))
	{
		Postfix[j++] = Pop(S);
		Postfix[j++] = ' ';
	}
	Postfix[j-1] = '\0';
	printf("%s\n",Postfix);
}

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->MaxSize = MaxSize;
	S->Top = -1; 
	return S;
}

bool IsEmpty(Stack S)
{
	return (S->Top == -1);
}

void Push(Stack S, ElementType X)
{
	S->Data[++(S->Top)] = X;
}

ElementType Peek(Stack S)
{
	return S->Data[(S->Top)];
}

ElementType Pop(Stack S)
{
	return S->Data[(S->Top)--];
}

bool IsSign(char *expr, int i)
{
	if(!i||(!isdigit(expr[i-1])&&(expr[i-1]!=')'))) return true;
	else return false;
}

char GetOp(char *expr, int *i, char *Postfix, int *j)
{
	if(isdigit(expr[(*i)]))
	{
		while(isdigit(expr[(*i)])||(expr[(*i)]=='.'))
		Postfix[(*j)++] = expr[(*i)++];
		Postfix[(*j)++] = ' ';
		(*i)--;
		return '0';
	}
	switch(expr[(*i)])
	{
		case '+':
			if(IsSign(expr, (*i)))
			{
				(*i)++;
				return GetOp(expr, i, Postfix, j);
			}
			else return '+';
		case '-':
			if(IsSign(expr, (*i)))
			{
				Postfix[(*j)++] = '-';
				(*i)++;
				return GetOp(expr, i, Postfix, j);
			}
			else return '-';	
		default:
			return expr[(*i)];
	}
}

Precedence GetToken(char op)
{
	/*返回运算符优先级*/
	switch(op)
	{
		case '(': return lpr;
		case ')': return rpr;
		case '+': return plus;
		case '-': return minus;
		case '*': return times;
		case '/': return divide;
		case '\0': return eos;
		default: return operand;
	}
}
