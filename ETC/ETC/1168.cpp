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
		if (i == N - 1) //������ ���� �ϳ����
			printf(">\n"); //��
		else
			printf(", "); //�� �̻� ���Ҵٸ� 

		q.erase(q.begin() + idx);
		idx += (K - 1); //�����ְ�
		if (--cpyN > 0)
			idx %= cpyN; //���� ������ŭ mod����
	}
}