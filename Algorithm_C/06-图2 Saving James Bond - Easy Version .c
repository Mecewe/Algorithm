/*
Tip:double %lf
	float %f
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double r;
typedef struct{
	int x;
	int y;
	int visited;
}Coordinates;

int ReadC(Coordinates* C, int n);
double SqrtC(int x1, int x2, int y1, int y2);
int IsTrue(Coordinates* C, int t);

int DFS(Coordinates* C,int k, int t)
{
	double R = r + 7.5;
	static int p = 0;
	int i,T;
	if (p && IsTrue(C, t)){
		return 1;
	}
	if (p == 0){
		for (i = 0; i < k; i++){
			if (R - SqrtC(C[i].x, 0, C[i].y, 0) >= 0.0 && C[i].visited != 1){
				C[i].visited = 1;
				p = 1;
				T = DFS(C, k, i);
				if (T==1){
					return T;
				}
			}
		}
	}
	else{
		for (i = 0; i < k; i++){
			if (C[i].visited != 1 && (r - SqrtC(C[i].x, C[t].x, C[i].y, C[t].y) >= 0.0)){
				C[i].visited = 1;
				T = DFS(C, k, i);
				if (T==1){
					return T;
				}
			}
		}
	}
	return 0;
}

int IsTrue(Coordinates* C, int t)
{
	if (50 - fabs(C[t].x) <= r || 50 - fabs(C[t].y) <= r)
		return 1;
	else
		return 0;
}

double SqrtC(int x1, int x2, int y1, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


int main()
{
	int N, p;
	scanf("%d %lf", &N, &r);
	Coordinates* C;
	C = (Coordinates*)malloc(sizeof(Coordinates)*N);
	ReadC(C,N);
	p = DFS(C, N, 0);
	if (p == 1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}

int ReadC(Coordinates* C, int n)
{
	for (int i = 0; i < n; i++){
		scanf("%d %d", &C[i].x, &C[i].y);
		C[i].visited = 0;
	}
	return 0;
}
