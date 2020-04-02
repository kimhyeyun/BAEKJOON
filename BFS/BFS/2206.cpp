#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

#define MAX 1001

int N, M;
int dir[][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int map[MAX][MAX];
bool Visited[MAX][MAX][2]; //방문여부 

int CntMap() {
	queue<pair<pair<int, int>, pair< bool, int> > > q; //좌표, 벽을뚫었는지 여부,최단거리
	q.push(make_pair(make_pair(0, 0), make_pair(false, 1)));
	Visited[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool wall = q.front().second.first;
		int cnt = q.front().second.second;

		q.pop();

		if (x == N - 1 && y == M - 1)
			return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];


			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] == 0 && !Visited[nx][ny][wall]) {
					q.push(make_pair(make_pair(nx, ny), make_pair(wall, cnt + 1)));
					Visited[nx][ny][wall] = true;

				}
				else if (map[nx][ny] == 1 && wall == false) {
					Visited[nx][ny][wall] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(true, cnt + 1)));

				}
			}
		}

	}
		return -1; //못가면


}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int asw = CntMap();

	printf("%d\n", asw);
}