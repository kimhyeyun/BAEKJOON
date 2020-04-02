#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX 101

int N;
int matrix[MAX][MAX]; //지점 행렬 - 각 지역의 높이가 들어있음
bool visited[MAX][MAX]; //방문여부

void CountRegion(int x, int y, int height) { //인접해있는 지역들을 방문!
	queue<pair<int, int> > q;
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };

	q.push(make_pair(x, y));

	visited[x][y] = true;

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (matrix[nx][ny] > height && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}


int main() {
	cin >> N;

	int max_h = 1;
	int min_h = 100;
	int max_num = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];

			min_h = min(min_h, matrix[i][j]);
			max_h = max(max_h, matrix[i][j]);
		}
	}

	for (int i = min_h; i < max_h; i++) {

		memset(visited, false, sizeof(visited));

		int sz = 0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (!visited[a][b] && matrix[a][b] > i) {
					CountRegion(a, b, i);
					sz++; //각 강수량 마다의 안전지역 수
				}
			}
		}
		max_num = max(max_num, sz); //그 중 최대
	}
	printf("%d\n", max_num);

}


