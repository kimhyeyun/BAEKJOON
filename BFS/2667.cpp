#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 26

int apartment[MAX][MAX];
int N;
int cnt;
vector<int> num;
bool visited[MAX][MAX] = { false, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void DFS(int a, int b) {
	visited[a][b] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (apartment[nx][ny] == 1 && !visited[nx][ny]) {
				DFS(nx, ny);
			}
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &apartment[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && apartment[i][j]) {
				cnt = 0;
				DFS(i, j);
				num.push_back(cnt);
			}
		}
	}
	sort(num.begin(), num.end());
	cout << num.size() << "\n";
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << "\n";
}