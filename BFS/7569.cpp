#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 101

int box[MAX][MAX][MAX] = { 0, }; //토마토가 들어있는 박스 ( 1:익은 토마토 , 0:익지않은 토마토, -1:토마토가 들어있지 않은 칸)
int days[MAX][MAX][MAX] = { 0, }; //익은 날
int M, N, H; //가로,세로,높이
queue<pair<pair<int, int>, int> > q;

void checktomato(int a, int b, int c) { //토마토가 익는 날 확인

	int dir[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} }; //왼쪽, 오른쪽, 위, 아래 

	q.push(make_pair(make_pair(a, b),c));

	while (!q. empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;

		q.pop();

		//각 방향으로
		for (int i = 0; i < 6; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nz = z + dir[i][2];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H) {
				if (box[nx][ny][nz] == 0 && (days[nx][ny][nz]>days[x][y][z]+1||days[nx][ny][nz]==0)) { 
					//익지않은 토마토가 있고, (익은 날이 0 이거나 이전검사보다 적으면)
					days[nx][ny][nz] = days[x][y][z] + 1;
					q.push(make_pair(make_pair(nx, ny), nz));
				}

			}
		}

	}
}

int main() {
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[k][j][i];

				if (box[k][j][i] == -1)
					days[k][j][i] = 1;
				if (box[k][j][i] == 1) {
					days[k][j][i] = 1;
				}
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[k][j][i] == 1)
					checktomato(k, j, i);
			}
		}
	}

	int max = 0;
	bool zero = false;

	//전체를 확인해 전부 익은날, 익지않은 토마토가 있는지 확인
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++) {
				if (days[k][j][i] > max)
					max = days[k][j][i];
				if (days[k][j][i] == 0)
					zero = true;
			}
		}
	}

	if (zero == true)
		printf("%d\n", -1);
	else
		printf("%d\n", max - 1);

}


