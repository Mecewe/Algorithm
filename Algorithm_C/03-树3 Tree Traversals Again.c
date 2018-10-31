/*
Tip:由确定的前序和中序推得后续 
*/

#include <stdio.h>
#include <stdbool.h>

#define Error -1
int *pre, *in;
int flag = 0;
typedef int Position;
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode
{
	ElementType * Data;
	Position Top;
	int MaxSize;
};

Stack CreateStack(int MaxSize){
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S){
	return S->Top == S->MaxSize - 1;
}

bool Push(Stack S, ElementType X){
	if (IsFull(S)){
		return false;
	}
	else{
		S->Data[++S->Top] = X;
		return true;
	}
}

bool Isempty(Stack S){
	return S->Top == -1;
}

ElementType Pop(Stack S){
	if (Isempty(S)){
		return Error;
	}
	else{
		return S->Data[S->Top--];
	}
}

void StackClear(Stack S){
	S->Top = -1;
}

void Post(int root, int start, int end){
	if (start > end){
		return;
	}
	int i = start;
	while (i < end && in[i] != pre[root]) i++;
	Post(root + 1, start, i - 1);
	Post(root + 1 + i - start, i + 1, end);
	if (!flag){
		printf("%d", pre[root]);
		flag = 1;
	}
	else{
		printf(" %d", pre[root]);
	}
}

int main()
{
	int N, i = 0, j = 0, val;
	char s[10];
	Stack S;
	scanf("%d", &N);
	S = CreateStack(N);
	pre = (int *)malloc(N*sizeof(int));
	in = (int *)malloc(N*sizeof(int));
	for (int k = 0; k < 2 * N; k++){
		scanf("%s", s);
		if (s[1] == 'u'){
			scanf("%d", &val);
			Push(S, val);
		}
		else{
			in[j++] = Pop(S);
		}
	}
	Post(0, 0, N - 1);
	return 0;
}


