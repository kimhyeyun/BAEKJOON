#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define MAX 51

int ocean[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { -1,1,0,0 ,1,1,-1,-1 };
int dy[] = { 0,0,-1,1,1,-1, 1,-1 };
int w, h;

void BFS(int i, int j) {
	queue<pair<int, int> > q;
	q.push(make_pair(i, j)); 
	visited[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;

			if (!visited[nx][ny] && ocean[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(){
	cin >> w >> h;
	while (w != 0 && h != 0) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = false;
				ocean[i][j] = 0;
			}
		}
		int ans = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> ocean[i][j];

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (!visited[i][j] && ocean[i][j] == 1) {
					BFS(i, j);
					ans++;
				}
		printf("%d\n", ans);
		cin >> w >> h;
	}

}