#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

#define MAX 101
int maze[MAX][MAX];
int days[MAX][MAX];
int N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Search(int i, int j) {
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	days[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
				if (maze[nx][ny] == 1 && days[nx][ny] == 0) {
					days[nx][ny] = days[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf_s("%1d", &maze[i][j]);

	Search(0, 0);

	printf("%d\n", days[N - 1][M - 1]);
}