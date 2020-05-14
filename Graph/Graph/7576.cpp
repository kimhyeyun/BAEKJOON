#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

#define MAX 1001

int tomato[MAX][MAX];
int days[MAX][MAX];
int N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue < pair<int, int> > q;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == -1)
				days[i][j] = 1;
			if ( tomato[i][j] == 1) {
				q.push(make_pair(i, j));
				days[i][j] = 1;
			}
		}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((0 <= nx && nx < M) && (0 <= ny && ny < N)) {
				if (tomato[nx][ny] == 0 && (days[nx][ny] == 0 || days[nx][ny] > days[x][y] + 1)) {
					days[nx][ny] = days[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int max = 0;
	bool zero = false;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			if (days[i][j] > max)
				max = days[i][j];
			if (days[i][j] == 0)
				zero = true;
		}

	if (zero)
		printf("-1\n");
	else
		printf("%d\n", max-1);
}