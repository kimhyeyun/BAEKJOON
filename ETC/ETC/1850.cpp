#include<iostream>
#include<stdio.h>
using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	long long a, b;
	cin >> a >> b;

	int g = gcd(a, b);

	for (int i = 0; i < g; i ++ ) {
		printf("1");
	}
	printf("\n");
}