#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

int N, M;
bool flag;
#define MAX 20001
vector<int> graph[MAX];
int visited[MAX];

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size();i++) {
			int a = graph[x][i];
			if (visited[a] == 0) {
				q.push(a);
				if (visited[x] == 1)
					visited[a] = 2;
				else
					visited[a] = 1;
			}
			else if ( visited[a] == visited[x])
				flag = true;
		}

	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		flag = false;
		cin >> N >> M;
		memset(visited, 0, MAX);
		while (M--) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0)
				BFS(i);
		}
		if (flag)
			printf("NO\n");
		else
			printf("YES\n");
		for (int i = 0; i <= N; i++)
			graph[i].clear();
	}
}

