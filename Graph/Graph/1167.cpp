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

	//���Ƿ� ������ root 1�����κ����� �Ÿ��� ���ϱ� ���� bfsŽ��
	BFS(1);

	//bfs�� ���� root�� ���� �� ���� �Ÿ��� ���������� ���� �� ���� ã��
	int start = 1;
	for (int i = 2; i <= N; i++) {
		if (dist[i] > dist[start])
			start = i;
	}

	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));

	//�տ��� ã�� ���� root�� �Ͽ� �ٽ� �̷κ����� �� ���� �Ÿ��� ����
	BFS(start);

	//�ٽ� root�� ���� ���� �ָ� ������ ���� ã��
	for (int i = 1; i <= N; i++) {
		if (dist[start] < dist[i])
			start = i;
	}

	printf("%d\n", dist[start]);
}