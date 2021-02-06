#include<stdio.h>

int main(){
	int a,b;
	int sum=0;
	char c;
	scanf("%d",&a);
	while((c=getchar())!='='){
		scanf("%d",&b);
		if(c=='/'&&b==0){
			printf("ERROR\n");
			return 0;
		}
		switch(c){
			
			case '+':sum = a+b;break;
			case '-':sum = a-b;break;
			case '*':sum = a*b;break;
			case '/':sum = a/b;break;
			default:printf("ERROR\n");return 0;
		}
		a=sum;
	}
	printf("%d\n",a);
	return 0;
}
