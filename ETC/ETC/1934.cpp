#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int a, b;
		cin >> a >> b;
		int g = gcd(a, b);
		printf("%d\n", (a * b) / g);
	}
}