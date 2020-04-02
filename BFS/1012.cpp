#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

#define MAX 50

int bachu[MAX][MAX];
bool visited[MAX][MAX];
int M, N, cnt;

void zirungi(int a, int b);

int main() {
	int T, K;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cnt = 0;
		memset(bachu, 0, sizeof(bachu));
		memset(visited, false, sizeof(visited));

		cin >> M >> N; //가로, 세로
		
		cin >> K; //배추 갯수

		for (int num = 0; num < K; num++) {
			int X, Y;
			cin >> X >> Y; //배추 위치
			bachu[X][Y] = 1;
		}
		/*for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j)
				cout << bachu[j][i];
			printf("\n");
		}*/

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bachu[j][i] == 1&&(!visited[j][i])) {
					zirungi(j, i);
					cnt++;
				}
			}
		}
		printf("%d", cnt);

	}
}

void zirungi(int a, int b) {
	int dx[] = { 0,-1,0,1 };
	int dy[] = { -1,0,1,0 };

	queue<pair<int, int> > zi;

	visited[a][b] = true;
	zi.push(make_pair(a, b));

	while (!zi.empty()) {
		int x = zi.front().first;
		int y = zi.front().second;

		zi.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (bachu[nx][ny] == 1 && !visited[nx][ny]) {
					zi.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}