#include<iostream>
#include<stdio.h>
using namespace std;

int factorial(int a) {
	if (a == 1)
		return 1;
	return a * factorial(a - 1);
}

int main() {
	int N;
	cin >> N;
	int n = factorial(N);
	printf("%d\n", n);
}