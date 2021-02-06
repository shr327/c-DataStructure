#include<stdio.h>

int MaxSub(int a[],int n){
	int max_sub = 0;
	int sub =  0;
	int i;
	for(i=0;i<n;i++){
		sub+=a[i];
		if(sub > max_sub) max_sub = sub;
		if(sub < 0)sub = 0;
	}
	return max_sub;
}

int main(){
	int i, n, max_sub;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	max_sub = MaxSub(a,n);
	printf("%d",max_sub);
	return 0;
}
