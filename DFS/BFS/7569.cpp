#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 101

int box[MAX][MAX][MAX] = { 0, }; //�丶�䰡 ����ִ� �ڽ� ( 1:���� �丶�� , 0:�������� �丶��, -1:�丶�䰡 ������� ���� ĭ)
int days[MAX][MAX][MAX] = { 0, }; //���� ��
int M, N, H; //����,����,����
queue<pair<pair<int, int>, int> > q;

void checktomato(int a, int b, int c) { //�丶�䰡 �ʹ� �� Ȯ��

	int dir[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} }; //����, ������, ��, �Ʒ� 

	q.push(make_pair(make_pair(a, b),c));

	while (!q. empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;

		q.pop();

		//�� ��������
		for (int i = 0; i < 6; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nz = z + dir[i][2];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H) {
				if (box[nx][ny][nz] == 0 && (days[nx][ny][nz]>days[x][y][z]+1||days[nx][ny][nz]==0)) { 
					//�������� �丶�䰡 �ְ�, (���� ���� 0 �̰ų� �����˻纸�� ������)
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

	//��ü�� Ȯ���� ���� ������, �������� �丶�䰡 �ִ��� Ȯ��
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


