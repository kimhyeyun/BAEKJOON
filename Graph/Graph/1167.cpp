#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define MAX 100001

vector<pair<int, int> > tree[MAX];
int N;
int ans;
int dist[MAX];
bool visited[MAX];

void BFS(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int i = 0; i < tree[n].size(); i++) {
			int nn = tree[n][i].first;
			if (visited[nn] == false) {
				dist[nn] = dist[n] + tree[n][i].second;
				q.push(nn);
				visited[nn] = true;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		while (1) {
			int v, d;
			cin >> v;
			if (v == -1)
				break;
			cin >> d;
			tree[x].push_back(make_pair(v, d));
		}
	}

	//임의로 설정한 root 1번으로부터의 거리를 구하기 위한 bfs탐색
	BFS(1);

	//bfs를 통해 root로 부터 각 저의 거리를 저장했으니 가장 먼 점을 찾음
	int start = 1;
	for (int i = 2; i <= N; i++) {
		if (dist[i] > dist[start])
			start = i;
	}

	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));

	//앞에서 찾은 점을 root로 하여 다시 이로부터의 각 점의 거리를 구함
	BFS(start);

	//다시 root로 부터 가장 멀리 떨어진 점을 찾음
	for (int i = 1; i <= N; i++) {
		if (dist[start] < dist[i])
			start = i;
	}

	printf("%d\n", dist[start]);
}