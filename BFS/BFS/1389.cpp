#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 101

int Relation[MAX][MAX];
int visited[MAX];

int N, M;

void Checkcnt(int a) {
	queue < int> q;
	visited[a] = 1;
	q.push(a);

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (Relation[n][i] == 1 && visited[i] == 0) {
				visited[i] = visited[n] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	 
	int min = 5001;
	int aws;
	while (M--) {
		int x, y;
		cin >> x >> y;
		Relation[x][y] = 1;
		Relation[y][x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++)
			visited[j] = false;

		int sum = 0;

		Checkcnt(i);
		for (int k = 1; k <= N; k++) {
			if (i == k)
				continue;
			else
				sum += (visited[k] - 1);
		}

		if (sum < min) {
			min = sum;
			aws = i;
		}
	}

	printf("%d\n", aws);
}