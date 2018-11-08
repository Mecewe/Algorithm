/*
Tip:缩短运行时间方法：按秩归并和路径压缩 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXSIZE];

SetName Find(SetType S, ElementType X)
{
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}

void Union(SetType S, SetName Root1, SetName Root2)
{
	if (S[Root1] < S[Root2]){
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
	else{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	
}

void Initialization(SetType S, int n)
{
	for (int i = 0; i < n; i++)
		S[i] = -1;
}

void Input_connection(SetType S)
{
	ElementType n, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &n, &v);
	Root1 = Find(S, n - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2)
		Union(S, Root1, Root2);	
}

void Check_connection(SetType S)
{
	ElementType n, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &n, &v);
	Root1 = Find(S, n - 1);
	Root2 = Find(S, v - 1);
	if (Root1 == Root2)
		printf("yes\n");
	else
		printf("no\n");
}

void Check_network(SetType S, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++){
		if (S[i] <0) count++;
	}
	if (count == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", count);
}


int main()
{
	SetType S;
	int n;
	char in;
	scanf("%d\n", &n);
	Initialization(S, n);
	do{
		scanf("%c", &in);
		switch (in){
		case 'I':Input_connection(S); break;
		case 'C':Check_connection(S); break;
		case 'S':Check_network(S, n); break;
		}

	} while (in != 'S');
	return 0;
}

