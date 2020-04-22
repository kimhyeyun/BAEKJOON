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

	it = q.begin(); //맨처음
	printf("<");

	while (q.size() != 1) {
		for (int i = 0; i < K - 1; i++) { //k번째 찾기
			++it;
			if (it == q.end()) //마지막이면
				it = q.begin(); //맨앞으로
		}
		printf("%d, ", *it); //출력
		it = q.erase(it); //삭제
		if (it == q.end()) //끝이면
			it = q.begin(); //다시 맨앞
	}
	printf("%d>", *it); //마지막 출력
}