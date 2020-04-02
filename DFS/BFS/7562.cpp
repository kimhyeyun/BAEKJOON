#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

#define MAX 301

int Chess[MAX][MAX] = { 0, };  //체스판
bool visited[MAX][MAX] = { false, };  //방문여부 체크 행렬
int I; //체스판의 크기

void howMany(int a,int b,int c,int d) {
	queue<pair<int, int> > q;

	q.push(make_pair(a, b));
	visited[a][b] = true;

	int dx[] = { -2,-1,1,2 };
	int dy[][2] = { {-1,1},{-2,2},{-2,2},{-1,1} };  //나이트의 이동가능 방향

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				int nx = x + dx[i];
				int ny = y + dy[i][j];

				if (nx >= 0 && nx < I && ny >= 0 && ny < I) {
					if (Chess[nx][ny] == 0&&!visited[nx][ny]) {
						Chess[nx][ny] = Chess[x][y] + 1;
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> I;
		
		int cx, cy, gx, gy;
		cin >> cx >> cy >> gx >> gy;

		//Chess[cx][cy] = 1;

		howMany(cx, cy,gx,gy);

		cout << Chess[gx][gy] << "\n";

		memset(Chess, 0, sizeof(Chess));
		memset(visited, false, sizeof(visited));
	}
}