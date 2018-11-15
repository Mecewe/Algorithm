/*
Tip:The application of BFS(Queue)
*/
#include <stdio.h>

#define MAXN 10001

int map[MAXN][MAXN], visited[MAXN];

int BFS(int v,int n)
{
	int i,queue[MAXN],rear,front,t;
	int count = 1, level = 0, last = v, tail;
	for (i = 1; i <= n; i++) visited[i] = 0;
	rear = front = 0;
	visited[v] = 1;
	queue[++rear] = v;
	while (front < rear){
		t = queue[++front];
		for (i = 1; i <= n; i++){
			if (map[t][i] && !visited[i]){
				queue[++rear] = i;
				count++;
				visited[i] = 1;
				tail = i;
			}
		}
		if (t == last){
			level++; last = tail;
		}
		if (level == 6) break;
	}
	return count;
}

int main()
{
	int N,M,i,x,y;
	int count;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d", &x, &y);
		map[x][y] = map[y][x] = 1;
	}
	for (i = 1; i <= N; i++){
		count = BFS(i,N);
		printf("%d: %.2f%%\n", i, (float)count / N*100);
	}
	return 0;
}

