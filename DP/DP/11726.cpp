#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int rectangle[1001];
	rectangle[0] = 1;
	rectangle[1] = 1;

	for (int i = 2; i <= N; i++) {
		rectangle[i] = (rectangle[i - 1] + rectangle[i - 2]) % 10007;
	}
	printf("%d\n", rectangle[N]);
}