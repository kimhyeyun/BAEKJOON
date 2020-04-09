#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	int T;
	int Sum[11];

	Sum[1] = 1;
	Sum[2] = 2;
	Sum[3] = 4;

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 4; i <= N; i++)
			Sum[i] = Sum[i - 1] + Sum[i - 2] + Sum[i - 3];

		printf("%d\n", Sum[N]);
	}
}