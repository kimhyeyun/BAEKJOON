#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

bool visited[1001];
int N, M, V;
int graph[1001][1001];

void DFS(int start) {
	visited[start] = true;
	printf("%d ", start);
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && graph[start][i] == 1) {
			visited[i] = true;
			DFS(i);
		}
	}
	return;
}

void BFS(int start) {
	queue<int> q;
	visited[start] = false;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		printf("%d ", x);
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i] && graph[x][i] == 1) {
				q.push(i);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	while (M--) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	DFS(V);
	printf("\n");
	BFS(V);
}