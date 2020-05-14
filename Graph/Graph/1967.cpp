#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define MAX 10001

vector<pair<int, int> > tree[MAX];
int N;
bool visited[MAX];
int dist = 0;
int farthestNode = 0;

void DFS(int n, int c) {
	if (visited[n])
		return;
	visited[n] = true;

	if (dist < c) {
		dist = c;
		farthestNode = n;
	}
	for (int i = 0; i < tree[n].size(); i++)
		DFS(tree[n][i].first, c + tree[n][i].second);
}

int main() {
	cin >> N;

	for (int i = 1; i < N; i++) {
		int n, v, d;
		cin >> n >> v >> d;

		tree[n].push_back(make_pair(v, d));
		tree[v].push_back(make_pair(n, d));
	}
	DFS(1, 0);

	memset(visited, false, sizeof(visited));
	dist = 0;
	DFS(farthestNode, 0);

	printf("%d\n", dist);


}