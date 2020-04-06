#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * (i + 1) - 1; k++) {
			if (k % 2 == 0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}