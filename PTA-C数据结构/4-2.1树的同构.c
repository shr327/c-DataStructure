#include<stdio.h>
#include<stdlib.h>

#define MaxN 100
#define Null -1

typedef char ElementType;
typedef int Tree;
 
struct TNode{
	ElementType Data;
	Tree Left;
	Tree Right;
}T1[MaxN], T2[MaxN];

int N, check[MaxN]; //check��������Ѱ�����ĸ���� 

Tree BuildTree(struct TNode T[])
{
	int Root=Null, i; //�տ�ʼ�������Ϊ�գ���Ϊ������ʱ��ɷ���Null 
	char cl, cr;
	scanf("%d",&N);
	if(N) //�����Ϊ�����Ļ� 
	{
		for(i=0;i<N;i++) check[i] = 0;
		for(i=0;i<N;i++)
		{
			scanf("\n%c %c %c",&T[i].Data, &cl, &cr);//�ѻ��з�����ǰ��Ե�ǰ��scanf��Ļس��������һ��scanf�����лس���һ������ 
			if(cl!='-')
			{
				T[i].Left = cl-'0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;
			if(cr!='-')
			{
				T[i].Right = cr-'0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}
		i=0;
		while(check[i]!=0) i++;
		Root = i;	
	}
	return Root;
}

int Isomorphic(Tree R1, Tree R2)
{
	if(R1==Null&&R2==Null) return 1;
	if((R1!=Null&&R2==Null)||(R1==Null&&R2!=Null)) return 0;
	if(T1[R1].Data!=T2[R2].Data) return 0;
	if(T1[R1].Left==Null&&T2[R2].Left==Null) return Isomorphic(T1[R1].Right, T2[R2].Right);
	if((T1[R1].Left!=Null&&T2[R2].Left!=Null)&&(T1[T1[R1].Left].Data==T2[T2[R2].Left].Data))
		return Isomorphic(T1[R1].Left, T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right);
	else return Isomorphic(T1[R1].Left, T2[R2].Right)&&Isomorphic(T1[R1].Right, T2[R2].Left);
}

int main()
{
	Tree R1, R2; //���Ƚ�����������R1��R2Ϊ���ĸ���� 
	R1 = BuildTree(T1); 
	R2 = BuildTree(T2);
	if(Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
