#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define MAX 100001
int team[MAX];
bool visited[MAX];
bool done[MAX];
int N,cnt;

void DFS(int start) {
	visited[start] = true;

	int n = team[start];
	if (!visited[n])
		DFS(n);
	else if (!done[n]) {
		for (int i = n; i != start; i = team[i])
			cnt++;
		cnt++;
	}
	done[start] = true;

}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			team[i] = 0;
			visited[i] = false;
			done[i] = false;
		}
		for (int i = 1; i <= N; i++)
			cin >> team[i];
		for (int i = 1; i <= N; i++) {
			if (!visited[i])
				DFS(i);
		}
		printf("%d\n", N-cnt);
	}
}