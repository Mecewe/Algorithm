/*
Tip:此为简版Code 
	DFS 递归 
	BFS 队列 
*/

#include <stdio.h>

#define MAXSIZE 10

int visit[MAXSIZE];
int G[MAXSIZE][MAXSIZE];

void DFS(int i, int n)
{
	int j;
	visit[i] = 1;
	printf(" %d", i);
	for (j = 0; j < n; j++){
		if (!visit[j] && G[i][j]){
			DFS(j, n);
		}
	}
}

void BFS(int i, int n)
{
	int queue[MAXSIZE], rear, front, v, j;
	rear = front = -1;
	visit[i] = 1;
	queue[++rear] = i;
	while (front<rear)
	{
		v = queue[++front];
		printf(" %d", v);
		for (j = 0; j < n; j++){
			if (!visit[j]&&G[v][j]){
				visit[j] = 1;
				queue[++rear] = j;
			}
		}
	}
}


int main()
{
	int N, E, i,x,y;
	scanf("%d %d", &N, &E);
	for (i = 0; i < E; i++){
		scanf("%d %d", &x, &y);
		G[x][y] = G[y][x] = 1;
	}
	for (i = 0; i < MAXSIZE; i++){
		visit[i] = 0;
	}
	for (i = 0; i < N; i++){
		if (!visit[i]){
			printf("{");
			DFS(i, N);
			printf(" }\n");
		}
	}
	for (i = 0; i < MAXSIZE; i++){
		visit[i] = 0;
	}
	for (i = 0; i < N; i++){
		if (!visit[i]){
			printf("{");
			BFS(i, N);
			printf(" }\n");
		}
	}
	return 0;
}

