#include<iostream>
#include<stdio.h>	
#include<algorithm>

using namespace std;

#define MAX 21

int R, C;
char board[MAX][MAX];
bool alphabet[26] = { false, }; //alphabet ��������?

int dir[][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int cnt = 0;

//dfs
void checkCnt(int startx,int starty,int count) {
	cnt = max(cnt, count); //�ִ밪 ���ϴ� ��


	for (int i = 0; i < 4; i++) {
		int nx = startx + dir[i][0];
		int ny = starty + dir[i][1];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			int k = (int)board[nx][ny] - 65; 
			if (!alphabet[k]) { //������������
				alphabet[k] = true; //���������ϰ�
				checkCnt(nx, ny, count + 1); //�ٽ� dfs
				alphabet[k]=false; //�� dfs�� ������ �� alphabet�� ����, �ٸ� �������� �������� �־���ϹǷ� 
			}
		}
	}
	return;
}

int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		/*for (int j = 0; j < C; j++) {
			scanf_s("%1c", &board[i][j]);
		}*/
		cin >> board[i];
	}

	alphabet[board[0][0] - 65] = true;
	checkCnt(0,0,1);
	printf("%d\n", cnt);
}