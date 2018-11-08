/*
Tip:Creat();括号需要完整 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001
#define MIN -10001

int H[MAXN], size;

void Creat()
{
	size = 0;
	H[0] = MIN;
}

void Insert(int X)
{
	int i;
	for (i = ++size; H[i / 2] > X; i /= 2)
		H[i] = H[i / 2];
	H[i] = X;
}

int main()
{
	int N, M,i,x,j;
	scanf("%d %d", &N, &M);
	Creat();
	for (i = 0; i < N; i++){
		scanf("%d", &x);
		Insert(x);
	}
	for (i = 0; i < M; i++){
		scanf("%d", &j);
		printf("%d", H[j]);
		while (j>1){
			j /= 2;
			printf(" %d", H[j]);
		}
		printf("\n");
	}
	return 0;
}


