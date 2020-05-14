#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100001
vector<int> tree[MAX];
int result[MAX];
int N;
queue<int> q;

void BFS() {
	q.push(1);
	while (!q.empty()) {
		int start = q.front();
		q.pop();
		for (int i = 0; i < tree[start].size(); i++) {
			if (result[tree[start][i]] == 0) {
				result[tree[start][i]] = start;
				q.push(tree[start][i]);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	int fp, sp;
	for (int i = 1; i < N; i++) {
		cin >> fp >> sp;
		tree[fp].push_back(sp);
		tree[sp].push_back(fp);
	}
	BFS();

	for (int i = 2; i <= N; i++) {
		printf("%d\n", result[i]);
	}
}