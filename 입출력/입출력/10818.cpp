#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int min = 10000000;
	int max = 0;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x > max)
			max = x;
		if (x < min)
			min = x;
	}

	printf("%d %d\n", min, max);
}