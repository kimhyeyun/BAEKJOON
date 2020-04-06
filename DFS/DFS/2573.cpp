#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 301

int N, M;
int Information[MAX][MAX];
bool visited[MAX][MAX];
int Cnt = 0;

int dir[][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //방향

//빙하 녹이는 함수
void Melt() {
	int copy[MAX][MAX]; //빙하정보 복사할 행렬

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			copy[i][j] = Information[i][j]; //빙하정보 복사
	}

	for (int x = 1; x < N - 1; x++) {
		for (int y = 1; y < M - 1; y++) {
			if (copy[x][y]) { //0이 아니면
				int cnt = 0; //주변 0의 갯수
				for (int i = 0; i < 4; i++) {
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];

					if (copy[nx][ny] == 0)
						cnt++;
				}
				Information[x][y] = max(copy[x][y] - cnt, 0);//0만큼 빼준 값이랑 0이랑 비교해 음수면 0 넣기
			}
		}
	}
}

//분리된 덩어리 수 체킹하는 함수
//DFS 함수
void CntMethod(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (1 <= nx && nx < N - 1 && 1 <= ny && ny < M - 1) {
			if (Information[nx][ny] && !visited[nx][ny])
				CntMethod(nx, ny);
		}
	}



}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Information[i][j];
		}
	}
	int year = 0; //년

	while (1) {
		memset(visited, false, sizeof(visited));
		bool result = false; //결과
		Cnt = 0; //분리된 덩어리 갯수
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (Information[i][j] != 0 && !visited[i][j]) {
					Cnt++;
					if (Cnt == 2) { //2면 끝
						result = true;
						break;
					}
					CntMethod(i, j); 
				}
			}
		}
		if (result)
			break;
		if (Cnt == 0) { //0이면
			year = 0; //0출력
			break;
		}
		Melt();
		year++;
	}

	printf("%d\n", year);

}