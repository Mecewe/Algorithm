#include <stdio.h>
#include <stdlib.h>


typedef struct SNode *Stack;
struct SNode
{
	int data[1000];
	int Top;
};

void Push(Stack, int);
int Pop(Stack);
int M;

int main()
{
	Stack PtrS;
	int N,K,num=0;
	scanf("%d %d %d", &M, &N, &K);
	PtrS = (Stack)malloc(sizeof(struct SNode));
	int a[K][N],i, j, check[1000] = { 0 },t,count;
	for (i = 0; i < K; i++){
		for (j = 0; j < N; j++){
			scanf("%d", &a[i][j]);
		}
	}
	//PtrS->data[5] =1;
	//printf("==================================\n");
	//printf("%d\n",a[0][2]);
	//printf("%d\n",PtrS->data[5]);
	for (i = 0; i < K; i++){
		count=1;
		num=0;
		for (j = 0; j < N; j++){
			t = a[i][j];
			//printf("==================================\n");
			//printf("%d\n",t);
			while (count<=t){
				Push(PtrS, count++);
				num++;
			//	printf("done\n");
			}
			if(num>M){
				check[i] = 1; 
				break;
			}
			num--;
			if (Pop(PtrS) != a[i][j]){
				
				check[i] = 1; 
				//printf("check %d:%d\n",i,check[i]);
				break;
			}
			
		}
		//printf("==================================\n");
	}
	for (i = 0; i < K; i++){
		
		if (!check[i]){
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	free(PtrS);
	return 0;
}

void Push(Stack PtrS, int item)
{
	//printf("push\n");
	PtrS->data[++(PtrS->Top)] = item;
	return;
}

int Pop(Stack PtrS)
{
	//printf("pop\n");
	return(PtrS->data[(PtrS->Top)--]);
}
