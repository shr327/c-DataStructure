#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 500

typedef struct Node* BinTree;

struct Node{
	char name[N]; //目录或文件的名字
	BinTree firstchild;
	BinTree rightsib;
	int flag_file; // 1表示为目录，0表示文件 
};

BinTree InsertNode(BinTree T, char file[], int flag)
{
	BinTree TN = (BinTree)malloc(sizeof(struct Node));
	BinTree pre = T, ptr;
	strcpy(TN->name, file);
	TN->firstchild = TN->rightsib = NULL;
	TN->flag_file = flag;
	if(T->firstchild==NULL) //所在目录没孩子，直接插入结点 
	{
		T->firstchild  = TN;
		return T->firstchild; 
	} //处理的是第一行路径数据
	
	ptr = T->firstchild; //pre为前驱结点，ptr作为pre的后继结点
	while( ptr!=NULL&&((ptr->flag_file>TN->flag_file)||(ptr->flag_file==TN->flag_file&&strcmp(file,ptr->name)>0)) )
	// 非空 &&（级别小||同级别字母序大） 查找插入位置，使用后继指针，找到后插在前驱指针的后面 
	{
		pre = ptr;
		ptr = ptr->rightsib; //同时移动ptr和其前驱 
	} //第一行之后每一行的路径数据都要循环找起始位置
	
	if(ptr==NULL) //无处插入，插在兄弟链尾 
	{
		TN->rightsib = pre->rightsib;
		pre->rightsib = TN;
		return TN;
	}
	else if(!strcmp(ptr->name,TN->name)&&ptr->flag_file==TN->flag_file) //重复了 
	{
		free(TN);
		return ptr;
	}
	else //有插入位置 
	{
		if(!strcmp(pre->name,T->name)) //根目录的长子位，pre与ptr指针没动 
		{
			TN->rightsib = pre->firstchild;
			pre->firstchild = TN;
			
		}
		else //正常插入 
		{
			TN->rightsib = pre->rightsib;
			pre->rightsib = TN;
		}
		return TN;
	}
}

void slicingStr(BinTree T) //字符串切片算法 
{
	char str[261];
	char file[261];
	int idx = 0;
	int i, j;
	scanf("%s",str);
	for(i=0;i<strlen(str);i++) // 目录切片 
	{
		if(str[i]=='\\') //转义字符 
		{
			for(j=0;idx<i;file[j++] = str[idx++]);
			file[j] = '\0';
			idx++; // 跳过'\\' 
			printf("%s\n",file); 
		}
	}
	if(idx<strlen(str)) //判断底端是否是文件
		{
			for(j=0;idx<strlen(str);file[j++]=str[idx++]);
			file[j] = '\0';
			idx++;
			printf("%s\n",file); 
		}
	else printf("\n");
}

//建树算法只需要在字符串切片算法之上进行改动即可，把输出语句改为调用结点插入函数即可实现
void CreateTree(BinTree T)
{
	char str[261];
	char file[261];
	int idx = 0;
	int i, j;
	gets(str);
	for(i=0;i<strlen(str);i++) // 目录切片 
	{
		if(str[i]=='\\') //转义字符 
		{
			for(j=0;idx<i;file[j++] = str[idx++]);
			file[j] = '\0';
			idx++; // 跳过'\\'
			T = InsertNode(T, file, 1);
		}
	}
	if(idx<strlen(str)) //判断底端是否是文件
		{
			for(j=0;idx<strlen(str);file[j++]=str[idx++]);
			file[j] = '\0';
			idx++;
			T = InsertNode(T, file, 0);
		}	
}

void PreOrderTraversal(BinTree T, int space) //因为要输出空格，稍微改装遍历算法 
{
	if(T==NULL) return;
	int i;
	for(i=0;i<space;i++) printf(" ");
	printf("%s\n",T->name);
	PreOrderTraversal(T->firstchild, space+2);
	PreOrderTraversal(T->rightsib, space);
}

int main()
{
	int i, num;
	BinTree T = (BinTree)malloc(sizeof(struct Node));
	T->firstchild = T->rightsib = NULL;
	T->flag_file = 1; //root是目录
	strcpy(T->name, "root");
	scanf("%d",&num);
	for(i=0;i<=num;i++)
	{
		CreateTree(T);
	}
	PreOrderTraversal(T, 0); //初始化空格数为0，root 
	return 0;
}
