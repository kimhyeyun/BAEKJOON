#include<iostream>
#include<stdio.h>

using namespace std;

#define MAX 1001
int graph[MAX][MAX];
bool visited[MAX];
int N, M;

void DFS(int start) {
	visited[start] = true;
	for (int i = 1; i <= N; i++) {
		if (graph[start][i] == 1 && !visited[i])
			DFS(i);
	}
}

int main() {
	cin >> N >> M;
	int answ = 0;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			answ++;
		}
	}
	printf("%d\n", answ);
}