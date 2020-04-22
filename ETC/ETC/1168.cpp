#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main() {
	vector<int> q;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		q.push_back(i);

	int idx = K - 1;
	int cpyN = N;

	printf("<");

	for (int i = 0; i < N; i ++ ) {
		printf("%d", q[idx]);
		if (i == N - 1) //마지막 남은 하나라면
			printf(">\n"); //끝
		else
			printf(", "); //둘 이상 남았다면 

		q.erase(q.begin() + idx);
		idx += (K - 1); //더해주고
		if (--cpyN > 0)
			idx %= cpyN; //남은 갯수만큼 mod연산
	}
}