#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 301

int N, M;
int Information[MAX][MAX];
bool visited[MAX][MAX];
int Cnt = 0;

int dir[][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //����

//���� ���̴� �Լ�
void Melt() {
	int copy[MAX][MAX]; //�������� ������ ���

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			copy[i][j] = Information[i][j]; //�������� ����
	}

	for (int x = 1; x < N - 1; x++) {
		for (int y = 1; y < M - 1; y++) {
			if (copy[x][y]) { //0�� �ƴϸ�
				int cnt = 0; //�ֺ� 0�� ����
				for (int i = 0; i < 4; i++) {
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];

					if (copy[nx][ny] == 0)
						cnt++;
				}
				Information[x][y] = max(copy[x][y] - cnt, 0);//0��ŭ ���� ���̶� 0�̶� ���� ������ 0 �ֱ�
			}
		}
	}
}

//�и��� ��� �� üŷ�ϴ� �Լ�
//DFS �Լ�
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
	int year = 0; //��

	while (1) {
		memset(visited, false, sizeof(visited));
		bool result = false; //���
		Cnt = 0; //�и��� ��� ����
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (Information[i][j] != 0 && !visited[i][j]) {
					Cnt++;
					if (Cnt == 2) { //2�� ��
						result = true;
						break;
					}
					CntMethod(i, j); 
				}
			}
		}
		if (result)
			break;
		if (Cnt == 0) { //0�̸�
			year = 0; //0���
			break;
		}
		Melt();
		year++;
	}

	printf("%d\n", year);

}