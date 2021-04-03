#include <stdio.h>

#define MAXN 10000

int FindRoot(int person[], int num);

int main()
{
	int i, j, N, K, Q;
	int person1, person2, root1, root2;
	int sum, count;
	sum = count = 0;
	int person[MAXN+1];
	for(i=1;i<=MAXN;i++) person[i] = -1;
	scanf("%d", &N);
	for(i=0;i<N;i++) {
		scanf("%d", &K);
		scanf("%d", &person1);
		if(person1>sum) sum = person1;
		root1 = FindRoot(person, person1);
		for(j=1;j<K;j++) {
			scanf("%d", &person2);
			if(person2>sum) sum = person2;
			root2 = FindRoot(person, person2);
			if(root1!=root2) {
				count--;
				if(person[root1]<=person[root2]) {
					person[root1] += person[root2];
					person[root2] = root1;
				}
				else {
					person[root2] += person[root1];
					person[root1] = root2;
					root1 = root2;
				}
			}
		}
	}
	count += sum;
	printf("%d %d\n", sum, count);
	
	scanf("%d", &Q);
	for(i=0;i<Q;i++) {
		scanf("%d", &person1);
		scanf("%d", &person2);
		root1 = FindRoot(person, person1);
		root2 = FindRoot(person, person2);
		if(root1==root2) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}

int FindRoot(int person[], int num)
{
	if(person[num]<0) return num;
	return person[num] = FindRoot(person, person[num]);
}
