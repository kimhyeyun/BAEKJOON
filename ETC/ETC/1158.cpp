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

	vector<int>::iterator it;

	it = q.begin(); //��ó��
	printf("<");

	while (q.size() != 1) {
		for (int i = 0; i < K - 1; i++) { //k��° ã��
			++it;
			if (it == q.end()) //�������̸�
				it = q.begin(); //�Ǿ�����
		}
		printf("%d, ", *it); //���
		it = q.erase(it); //����
		if (it == q.end()) //���̸�
			it = q.begin(); //�ٽ� �Ǿ�
	}
	printf("%d>", *it); //������ ���
}