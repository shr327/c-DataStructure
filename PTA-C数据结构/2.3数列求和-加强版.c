#include <stdio.h>

int main()
{
	int Digit[100003] = {0},Sum[100003] = {0};
	int A, N, Flag, i;
	scanf("%d %d", &A, &N);
	for( i=1; i<=N; i++){
		Digit[i]=A;//将Digit数组中前N个元素赋A值；
	}
	for( i=1; i<=100003; i++){
		Sum[i] += Digit[i] * (N-i+1);
		Sum[i+1] = Sum[i] / 10;
		Sum[i] %= 10;
	}
	for( i=100003; i>=1; i--){
		if(Sum[i] != 0){
			Flag = i;
			break;
		}
	}
	for( i=Flag; i>=1; i--){
		printf("%d",Sum[i]);
	}
	return 0;
}
