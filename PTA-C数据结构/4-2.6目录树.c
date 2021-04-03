#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 500

typedef struct Node* BinTree;

struct Node{
	char name[N]; //Ŀ¼���ļ�������
	BinTree firstchild;
	BinTree rightsib;
	int flag_file; // 1��ʾΪĿ¼��0��ʾ�ļ� 
};

BinTree InsertNode(BinTree T, char file[], int flag)
{
	BinTree TN = (BinTree)malloc(sizeof(struct Node));
	BinTree pre = T, ptr;
	strcpy(TN->name, file);
	TN->firstchild = TN->rightsib = NULL;
	TN->flag_file = flag;
	if(T->firstchild==NULL) //����Ŀ¼û���ӣ�ֱ�Ӳ����� 
	{
		T->firstchild  = TN;
		return T->firstchild; 
	} //������ǵ�һ��·������
	
	ptr = T->firstchild; //preΪǰ����㣬ptr��Ϊpre�ĺ�̽��
	while( ptr!=NULL&&((ptr->flag_file>TN->flag_file)||(ptr->flag_file==TN->flag_file&&strcmp(file,ptr->name)>0)) )
	// �ǿ� &&������С||ͬ������ĸ��� ���Ҳ���λ�ã�ʹ�ú��ָ�룬�ҵ������ǰ��ָ��ĺ��� 
	{
		pre = ptr;
		ptr = ptr->rightsib; //ͬʱ�ƶ�ptr����ǰ�� 
	} //��һ��֮��ÿһ�е�·�����ݶ�Ҫѭ������ʼλ��
	
	if(ptr==NULL) //�޴����룬�����ֵ���β 
	{
		TN->rightsib = pre->rightsib;
		pre->rightsib = TN;
		return TN;
	}
	else if(!strcmp(ptr->name,TN->name)&&ptr->flag_file==TN->flag_file) //�ظ��� 
	{
		free(TN);
		return ptr;
	}
	else //�в���λ�� 
	{
		if(!strcmp(pre->name,T->name)) //��Ŀ¼�ĳ���λ��pre��ptrָ��û�� 
		{
			TN->rightsib = pre->firstchild;
			pre->firstchild = TN;
			
		}
		else //�������� 
		{
			TN->rightsib = pre->rightsib;
			pre->rightsib = TN;
		}
		return TN;
	}
}

void slicingStr(BinTree T) //�ַ�����Ƭ�㷨 
{
	char str[261];
	char file[261];
	int idx = 0;
	int i, j;
	scanf("%s",str);
	for(i=0;i<strlen(str);i++) // Ŀ¼��Ƭ 
	{
		if(str[i]=='\\') //ת���ַ� 
		{
			for(j=0;idx<i;file[j++] = str[idx++]);
			file[j] = '\0';
			idx++; // ����'\\' 
			printf("%s\n",file); 
		}
	}
	if(idx<strlen(str)) //�жϵ׶��Ƿ����ļ�
		{
			for(j=0;idx<strlen(str);file[j++]=str[idx++]);
			file[j] = '\0';
			idx++;
			printf("%s\n",file); 
		}
	else printf("\n");
}

//�����㷨ֻ��Ҫ���ַ�����Ƭ�㷨֮�Ͻ��иĶ����ɣ����������Ϊ���ý����뺯������ʵ��
void CreateTree(BinTree T)
{
	char str[261];
	char file[261];
	int idx = 0;
	int i, j;
	gets(str);
	for(i=0;i<strlen(str);i++) // Ŀ¼��Ƭ 
	{
		if(str[i]=='\\') //ת���ַ� 
		{
			for(j=0;idx<i;file[j++] = str[idx++]);
			file[j] = '\0';
			idx++; // ����'\\'
			T = InsertNode(T, file, 1);
		}
	}
	if(idx<strlen(str)) //�жϵ׶��Ƿ����ļ�
		{
			for(j=0;idx<strlen(str);file[j++]=str[idx++]);
			file[j] = '\0';
			idx++;
			T = InsertNode(T, file, 0);
		}	
}

void PreOrderTraversal(BinTree T, int space) //��ΪҪ����ո���΢��װ�����㷨 
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
	T->flag_file = 1; //root��Ŀ¼
	strcpy(T->name, "root");
	scanf("%d",&num);
	for(i=0;i<=num;i++)
	{
		CreateTree(T);
	}
	PreOrderTraversal(T, 0); //��ʼ���ո���Ϊ0��root 
	return 0;
}
