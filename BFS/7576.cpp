#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

#define MAX 1001

int N, M;
int max;
int box[MAX][MAX];
int days[MAX][MAX] = { 0, };

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int> > q;

<<<<<<< HEAD
=======
void Search(int a, int b);
>>>>>>> da1a5c7e796d0749e8c06a7f11941ed3ccef8da0

int main() {
	int x, max;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &x);
			box[j][i] = x;
			if (x == -1)
				days[j][i] = 1;
			if (x == 1) {
				q.push(make_pair(j, i));
				days[j][i] = 1;
			}

		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (0 <= newX && newX < N && 0 <= newY && newY < M) {
				if (box[newX][newY] == 0 && (days[newX][newY] > days[x][y] + 1 || days[newX][newY] == 0)) {
					days[newX][newY] = days[x][y] + 1;
					q.push(make_pair(newX, newY));
				}

			}
		}
	}


	max = 0;
	bool zero = false;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (days[j][i] > max)
				max = days[j][i];
			if (days[j][i] == 0)
				zero = true;
		}
	}

	if (zero == true)
		printf("%d\n", -1);
	else
		printf("%d\n", max - 1);


}

