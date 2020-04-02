#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define MAX 101

//미로 이차원 벡터
vector<vector<int>> maze(MAX, vector<int>(MAX, 0));
//경로수 이차원 벡터
vector<vector<int>> check(MAX, vector<int>(MAX, 0));

int N, M;

void searchMaze(int startx, int starty);
//함수 프로토타입

int main() {
	scanf_s("%d", &N);
	scanf_s("%d", &M);


	//입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}

	//시작지점은 1
	check[0][0] = 1;
	searchMaze(0, 0);

	printf("%d\n", check[N - 1][M - 1]);

}

void searchMaze(int startx, int starty) {
	queue<pair<int, int>> q;

	//방향 배열
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	//시작 점 push
	q.push(make_pair(startx, starty));

	//bfs여서 queue 사용
	while (!q.empty()) { //queue가 빌때까지
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (maze[nx][ny] == 1 && check[nx][ny] == 0) {
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}