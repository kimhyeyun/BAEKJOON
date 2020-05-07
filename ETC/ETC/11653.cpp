#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	int prime = 2;
	cin >> N;
	while (N != 1) {
		if (N % prime == 0) {
			printf("%d\n", prime);
			N /= prime;
		}
		else
			prime++;
	}
}