#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

#define MAX 101

int N, M;
bool graph[MAX][MAX];
int cnt[MAX];

int CntCousin(int a,int b) {
	queue<int> q;
	cnt[a] = 0;

	q.push(a);

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[n][i] && cnt[i]==-1) {
				q.push(i);
				cnt[i] = cnt[n] + 1;
				if (i == b)
					return cnt[i];
			}
		}
	}
	return -1;
}

int main() {
	cin >> N;
	memset(cnt, -1, N);

	int a, b; //촌수를 확인할 두 사람
	
	cin >> a >> b;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = true;
		graph[y][x] = true;
	}

	int result=CntCousin(a,b);

	printf("%d\n", result);

	//if (depth[b] != 0)
	//	printf("%d\n", depth[b]);
	//else
	//	printf("-1\n");

}