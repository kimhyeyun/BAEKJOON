#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

#define MAX 101

void BFS(int i, int j);

int vertex;

int incidentMatrix[MAX][MAX];
int visited[MAX][MAX];

int main() {
	cin >> vertex;


	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			cin >> incidentMatrix[i][j];
		}
	}
	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			if (incidentMatrix[i][j])
				BFS(i, j);
		}
	}



	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++)
			cout << visited[i][j] << " ";
		cout << "\n";
	}
}

void BFS(int i, int j) {
	queue<pair<int, int> > q;

	visited[i][j] = 1;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		for (int a = 0; a < vertex; a++) {
			if (incidentMatrix[q.front().second][a] && !visited[i][a]) {
				visited[i][a] = 1;
				q.push(make_pair(q.front().second, a));
			}
		}
		q.pop();
	}

}
