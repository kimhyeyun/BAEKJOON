#include<iostream>
#include<stdio.h>	
#include<algorithm>

using namespace std;

#define MAX 21

int R, C;
char board[MAX][MAX];
bool alphabet[26] = { false, }; //alphabet 지나갔나?

int dir[][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int cnt = 0;

//dfs
void checkCnt(int startx,int starty,int count) {
	cnt = max(cnt, count); //최대값 구하는 것


	for (int i = 0; i < 4; i++) {
		int nx = startx + dir[i][0];
		int ny = starty + dir[i][1];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			int k = (int)board[nx][ny] - 65; 
			if (!alphabet[k]) { //안지나갔으면
				alphabet[k] = true; //지나갔다하고
				checkCnt(nx, ny, count + 1); //다시 dfs
				alphabet[k]=false; //한 dfs가 끝나면 그 alphabet은 해제, 다른 방향으로 지나갈수 있어야하므로 
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