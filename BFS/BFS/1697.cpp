#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 100000
bool visited[MAX] = { false, };
int N, K;
int dr[] = { -1,1 };

int SearchBro(int a);

int main() {

	cin >> N >> K;
	int result = SearchBro(N);

	printf("%d\n", result);


}

int SearchBro(int a) {
	queue<pair<int, int> > q;

	q.push(make_pair(a, 0));
	visited[a] = true;

	while (!q.empty()) {
		int now = q.front().first; //현재위치
		int time = q.front().second; //시간

		q.pop();

		if (now == K) {
			return time;
		}

		for (int i = 0; i < 2; i++) {
			int nn = now + dr[i]; //다음 위치, 걸었을때(뒤나 앞)
			int nt = time + 1; //다음위치에 가는데 걸리는 시간

			if (nn >= 0 && nn < MAX) {
				if (visited[nn] == false) {
					visited[nn] = true;
					q.push(make_pair(nn, nt));
				}
			}
		}

		if (now * 2 < MAX) {
			if (visited[2 * now] == false) { //순간이동
				visited[2 * now] = true;
				q.push(make_pair(2 * now, time + 1));
			}
		}
	}
}