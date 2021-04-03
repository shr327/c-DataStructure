#include <stdio.h>

typedef enum {false, true} bool;

typedef struct TNode {
	int K1;
	int K2;
	int Left;
	int Right;
} Tree;

bool Check(Tree T[], int root);

int main()
{
	int i, N;
	scanf("%d", &N);
	Tree T[N];
	int check[N];
	for(i=0;i<N;i++) check[i] = 0;
	for(i=0;i<N;i++) {
		scanf("%d %d %d %d", &T[i].K1, &T[i].K2, &T[i].Left, &T[i].Right);
		check[T[i].Left] = check[T[i].Right] = 1;
	}
	for(i=0;i<N;i++)
		if(check[i]==0) break;
	if(Check(T, i)) printf("YES\n");
	else printf("NO\n");
	return 0;
}

bool Check(Tree T[], int root) {
	if(root==-1) return true;
	int rootk1, rootk2, left, right, lmax, rmin;
	rootk1 = T[root].K1;
	rootk2 = T[root].K2;
	lmax = left = T[root].Left;
	if(lmax!=-1) { //如果左子树存在，找到左子树的最大值用于判断二叉搜索树 
		while(T[lmax].Right!=-1)
			lmax = T[lmax].Right;
	}
	rmin = right = T[root].Right;
	if(rmin!=-1) { //如果右子树存在，找到右子树的最小值用于判断二叉搜索树 
		while(T[rmin].Left!=-1)
			rmin = T[rmin].Left;
	}
	if((left==-1||(T[lmax].K1<rootk1&&T[left].K2>=rootk2))&&\
	((right==-1)||(rootk1<=T[rmin].K1&&T[right].K2>=rootk2)))
		return(Check(T, left)&&Check(T, right));
	return false;
}
