#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

#define MAX 21

int R, C;
char board[MAX][MAX];
bool visited[MAX][MAX];
vector<char> vschar;

//dfs
int checkCnt() {
	visited[0][0] = true;
}

int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	int result = checkCnt();
}