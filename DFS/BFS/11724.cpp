#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

#define MAX 1001

int N, M;
vector<vector<int> > graph(MAX, vector<int>(MAX, 0));
bool visited[MAX] = { false, };

void checkConnected(int a) {
	queue<int> q;

	q.push(a);
	visited[a] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[x][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}

	}
}

int main() {
	int cnt = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			checkConnected(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
}
	