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
	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);
	int c = (a * b) / g;

	printf("%d %d\n", g, c);
}