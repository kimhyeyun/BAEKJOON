#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define MAX 26

int apartment[MAX][MAX];
bool visited[MAX][MAX];
int N;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int BFS(int i, int j) {
	int cnt = 0;
	visited[i][j] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (apartment[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	vector<int> ans;
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &apartment[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (apartment[i][j] == 1 && !visited[i][j]) {
				ans.push_back(BFS(i, j));
				answer++;
			}

		}
	}
	printf("%d\n", answer);
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
}