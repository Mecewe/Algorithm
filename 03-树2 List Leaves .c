/*
Tip:层序遍历(队列的思想） 
*/
#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T[MaxTree];

Tree BuildTree(struct TreeNode T[]);
void GetLeaves(Tree R);

int main()
{
	Tree R;
	R = BuildTree(T);
	GetLeaves(R);
	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	int N, i, root = Null, check[10];
	char cl, cr;
	scanf("%d", &N);
	if (N){
		for (i = 0; i < N; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			T[i].Element = i;
			scanf("\n%c %c", &cl, &cr);
			if (cl != '-'){
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else{
				T[i].Left = Null;
			}
			if (cr != '-'){
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else{
				T[i].Right = Null;
			}
		}
		for (i = 0; i < N; i++){
			if (!check[i]) break;
		}
		root = i;
	}
	return root;
}

void GetLeaves(Tree R)
{
	//层序遍历:从根节点开始依次将左右儿子入队，直到队列为空
	Tree Leaves[10] = { 0 }, n = 0;
	int front=0, rear=0;
	if (R == Null){
		return;
	}
	Leaves[rear++] = R;
	while (rear - front){
		int node = Leaves[front++];
		if (T[node].Left == Null && T[node].Right == Null){
			if (n++) printf(" ");
			printf("%c", T[node].Element+'0');

		}
		if (T[node].Left != Null){
			Leaves[rear++] = T[node].Left;
		}
		if (T[node].Right != Null){
			Leaves[rear++] = T[node].Right;
		}
	}
	return;
}
