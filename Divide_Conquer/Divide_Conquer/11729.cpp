#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

void Hanoimove(int num, int from, int by, int to) {
	if (num == 1)
		printf("%d %d\n", from, to);
	else {
		Hanoimove(num - 1, from, to, by);
		printf("%d %d\n", from, to);
		Hanoimove(num - 1, by, from, to);
	}
}


int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	printf("%d\n", (int)pow(2, N) - 1);
	Hanoimove(N, 1, 2, 3);
}