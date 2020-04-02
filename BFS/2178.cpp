#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define MAX 101

//�̷� ������ ����
vector<vector<int>> maze(MAX, vector<int>(MAX, 0));
//��μ� ������ ����
vector<vector<int>> check(MAX, vector<int>(MAX, 0));

int N, M;

void searchMaze(int startx, int starty);
//�Լ� ������Ÿ��

int main() {
	scanf_s("%d", &N);
	scanf_s("%d", &M);


	//�Է¹ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}

	//���������� 1
	check[0][0] = 1;
	searchMaze(0, 0);

	printf("%d\n", check[N - 1][M - 1]);

}

void searchMaze(int startx, int starty) {
	queue<pair<int, int>> q;

	//���� �迭
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	//���� �� push
	q.push(make_pair(startx, starty));

	//bfs���� queue ���
	while (!q.empty()) { //queue�� ��������
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