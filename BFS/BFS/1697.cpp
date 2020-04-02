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
		int now = q.front().first; //������ġ
		int time = q.front().second; //�ð�

		q.pop();

		if (now == K) {
			return time;
		}

		for (int i = 0; i < 2; i++) {
			int nn = now + dr[i]; //���� ��ġ, �ɾ�����(�ڳ� ��)
			int nt = time + 1; //������ġ�� ���µ� �ɸ��� �ð�

			if (nn >= 0 && nn < MAX) {
				if (visited[nn] == false) {
					visited[nn] = true;
					q.push(make_pair(nn, nt));
				}
			}
		}

		if (now * 2 < MAX) {
			if (visited[2 * now] == false) { //�����̵�
				visited[2 * now] = true;
				q.push(make_pair(2 * now, time + 1));
			}
		}
	}
}