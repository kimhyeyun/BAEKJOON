#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX 102
int N, M, K;
int BigBox[MAX][MAX] = { 0, }; //ū ������
bool checkBig[MAX][MAX] = { false, }; //�湮�Ͽ����� Ȯ���ϴ� �迭

void makeBox(int a,int b,int c,int d) { //��ĥ���ִ� �Լ�
	for (int i = 0; i < (c - a); i++) { //���⼭�� �־����� ��ǥ�� ������ ��ǥ�̹Ƿ� �����̸�ŭ ��ĥ
		for (int j = 0; j < (d - b); j++) { //��������, y��
			BigBox[a + i][b + j] = 1; //��ĥ
		}
	}
}

int checkYeongYeok(int a,int b) { //��ĥ�� �ȵǾ��ִ� �κ� ����Ȯ��
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };  //����

	int sz = 1;  //�� ������ ũ�� ����

	queue<pair<int, int> > q; 
	q.push(make_pair(a, b));
	checkBig[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) { 
				if (BigBox[nx][ny] == 0 && !checkBig[nx][ny]) { //���� ��ĥ�����ְ� �湮���� �ʾҴٸ�
					sz++; //���� �÷��ְ�
					q.push(make_pair(nx, ny));  //q�� Ǫ��
					checkBig[nx][ny] = true; //�湮������ ǥ��
				}
			}

		}
	}
	return sz; //Ȯ���� ������ ���� return
}

int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2; //(x1,y1) : ���� �� ��ǥ/ (x2,y2): �Ʒ��� �� ��ǥ
		makeBox(x1, y1, x2, y2); //��ĥ
	}
	int num = 0; //������ ���� ����
	vector<int> size; //�� ������ ���̸� ��Ƴ��� vector 

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (BigBox[j][i] == 0 && !checkBig[j][i]) {
				size.push_back(checkYeongYeok(j, i));
				num++;
			}
		}
	}
	printf("%d\n", num);
	sort(size.begin(), size.end()); //�������������� ����
	for (int i = 0; i < size.size(); i++)
		printf("%d ", size[i]);
}