#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode
{
	int v;
	Tree Left, Right;
	int flag;
};

Tree NewNode(int v)
{
	Tree T;
	T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = v;
	T->Left = NULL;
	T->Right = NULL;
	T->flag = 0;
	return T;
}

Tree insert(Tree T, int v)
{
	if (!T){
		T = NewNode(v);
	}
	else{
		if (v < T->v){
			T->Left = insert(T->Left, v);
		}
		else if (v >T->v){
			T->Right = insert(T->Right, v);
		}
	}
	return T;
}

Tree makeTree(int N)
{
	Tree T;
	int i, v;
	scanf("%d", &v);
	T = NewNode(v);
	for (i = 1; i < N; i++){
		scanf("%d", &v);
		T = insert(T, v);
	}
	return T;
}

int check(Tree T, int v)
{
	if (T->flag){
		if (v < T->v) return check(T->Left, v);
		else if (v>T->v) return check(T->Right, v);
		else return 0;
	}
	else{
		if (v == T->v){
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}

int judgeTree(Tree T, int N)
{
	int i,v,flag = 0;
	scanf("%d", &v);
	if (v != T->v) flag = 1;
	else T->flag = 1;

	for (i = 1; i < N; i++){
		scanf("%d", &v);
		if (!flag && !check(T, v)) flag = 1;
	}
	if (flag) return 0;
	else return 1;
}

void ResetTree(Tree T)
{
	if (T->Left) ResetTree(T->Left);
	if (T->Right) ResetTree(T->Right);
	T->flag = 0;
}

void FreeTree(Tree T)
{
	if (T->Left) FreeTree(T->Left);
	if (T->Right)  FreeTree(T->Right);
	free(T);
}

int main()
{
	int N, L, i;
	Tree T;
	scanf("%d", &N);
	while (N){
		scanf("%d", &L);
		T = makeTree(N);
		for (i = 0; i < L; i++){
			if (judgeTree(T, N)){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
			ResetTree(T);
		}
		FreeTree(T);
		scanf("%d", &N);
	}
	return 0;
}

