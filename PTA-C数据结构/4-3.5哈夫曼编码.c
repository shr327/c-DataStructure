#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 63

typedef enum {false, true} bool;

typedef struct {
	char Sym;
	int Prio;
	int CLength;
} Data;

typedef struct TNode *Tree;
struct TNode {
	char Sym;
	Tree Left;
	Tree Right;
};

typedef struct HTNode *HTree;
struct HTNode {
	int Data;
	HTree Left;
	HTree Right;
};

typedef struct HNode *Heap;
struct HNode {
	HTree Data[MAXN+1];
	int Size;
};

bool InsertTree(Tree T, char sym, char code[]);
bool CheckLength(Tree T, Data data[], int N);
void InsertHeap(Heap H, HTree x);
HTree DeleteHeap(Heap H);
int Calculate(HTree HT, int level);

int sum;

int main()
{
	int i, j, N, M, right;
	char sym, code[MAXN+1];
	scanf("%d\n", &N);
	Data data[N], order[N];
	for(i=0;i<N;i++) {
		if(i!=0) scanf(" ");
		scanf("%c %d", &data[i].Sym, &data[i].Prio);
	}
	scanf("%d\n", &M);
	Tree T;
	for(i=0;i<M;i++) {
		right = 1;
		T = (Tree)malloc(sizeof(struct TNode));
		T->Sym = 0;
		T->Left = T->Right = NULL;
		for(j=0;j<N;j++) {
			scanf("%c%s\n", &sym, code);
			data[j].CLength = strlen(code);
			if(right&&!InsertTree(T, sym, code)) right = 0;
		}
		if(right&&CheckLength(T, data, N)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

bool InsertTree(Tree T, char sym, char code[]) //建树检查是否满足前缀码要求 
{
	int i = 0, j;
	Tree TT;
	while(code[i+1]) { //i+1的目的是检查结点最后的位置是否为叶子结点，若不是则返回false 
		if(code[i]=='0') {
			if(!T->Left) {
				T->Left = (Tree)malloc(sizeof(struct TNode));
				T->Left->Sym = 0;
				T->Left->Left = T->Left->Right = NULL;
			}
			else if(T->Left->Sym) return false;
			T = T->Left;
		}
		else {
			if(!T->Right) {
				T->Right = (Tree)malloc(sizeof(struct TNode));
				T->Right->Sym = 0;
				T->Right->Left = T->Right->Right = NULL;
			}
			else if(T->Right->Sym) return false;
			T = T->Right;
		}
		i++;
	}
	if(code[i]=='0') {
		if(T->Left) return false;
		T->Left = (Tree)malloc(sizeof(struct TNode));
		T->Left->Sym = sym;
		T->Left->Left = T->Left->Right = NULL;
	}
	else {
		if(T->Right) return false;
		T->Right = (Tree)malloc(sizeof(struct TNode));
		T->Right->Sym = sym;
		T->Right->Left = T->Right->Right = NULL;
	}
	return true;
}

bool CheckLength(Tree T, Data data[], int N) //建最大堆和标准哈夫曼树检查长度 
{
	int i, minsum, trusum = 0;
	Heap H = (Heap)malloc(sizeof(struct HNode));
	H->Data[0] = (HTree)malloc(sizeof(struct HTNode));
	H->Data[0]->Data = H->Size = 0;
	HTree HT;
	for(i=0;i<N;i++) {
		trusum += data[i].Prio*data[i].CLength;
		HT = (HTree)malloc(sizeof(struct HTNode));
		HT->Data = data[i].Prio;
		HT->Left = HT->Right = NULL;
		InsertHeap(H, HT);
	}
	for(i=1;i<N;i++) {
		HT = (HTree)malloc(sizeof(struct HTNode));
		HT->Left = DeleteHeap(H);
		HT->Right = DeleteHeap(H);
		HT->Data = HT->Left->Data+HT->Right->Data;
		InsertHeap(H, HT);
	}
	HT = DeleteHeap(H);
	sum = 0;
	minsum = Calculate(HT, 0);
	return minsum==trusum;
}

void InsertHeap(Heap H, HTree x)
{
	int i = ++H->Size;
	for(;x->Data<H->Data[i/2]->Data;i/=2)
		H->Data[i] = H->Data[i/2];
	H->Data[i] = x;
}

HTree DeleteHeap(Heap H)
{
	int parent ,child;
	HTree min, x;
	min = H->Data[1];
	x = H->Data[H->Size--];
	for(parent=1;parent*2<=H->Size;parent=child) {
		child = parent*2;
		if(child!=H->Size&&H->Data[child+1]->Data<H->Data[child]->Data) child++;
		if(x->Data<=H->Data[child]->Data) break;
		H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = x;
	return min;
}

int Calculate(HTree HT, int level)
{ 
	if(!HT) return 0;
	if(!HT->Left&&!HT->Right) sum += HT->Data*level;
	Calculate(HT->Left, level+1);
	Calculate(HT->Right, level+1);
	return sum;
}

