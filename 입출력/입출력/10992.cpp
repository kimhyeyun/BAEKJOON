#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++)
			printf(" ");

		if (i == 1 || i == N) {
			for (int j = 1; j <= (i - 1) * 2 + 1; j++)
				printf("*");
		}
		else {
			printf("*");
			for (int j = 1; j < 2 * i-2; j++) {
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
}