#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef int ElementType;
struct AVLNode
{
	ElementType data;
	AVLTree Left, Right;
	int Height;
};

int Max(int a, int b)
{
	return a > b ? a : b;
}

int GetHeight(Position T)
{
	if (T == NULL){
		return -1;
	}
	return T->Height;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(A->Height, GetHeight(B->Right)) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T, ElementType X)
{
	if (!T){
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->data = X;
		T->Left = T->Right = NULL;
		T->Height = 0;
	}
	else if (X < T->data){
		T->Left = Insert(T->Left, X);
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2){
			if (X < T->Left->data)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);
		}
	}
	else if (X > T->data){
		T->Right = Insert(T->Right, X);
		if (GetHeight(T->Left) - GetHeight(T->Right) == -2){
			if (X >T->Right->data)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
		}
	}
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}

int main()
{
	int n, x;
	AVLTree T = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		T = Insert(T, x);
	}
	printf("%d\n", T->data);
	return 0;
}


