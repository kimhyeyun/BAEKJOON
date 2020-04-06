#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int k = 0; k <= i; k++)
			printf("*");
		for (int j = 0; j < N - i-1; j++)
			printf(" ");
		for (int j = 0; j < N - i-1; j++)
			printf(" ");
		for (int k = 0; k <= i; k++)
			printf("*");

		printf("\n");
	}

	for (int i = 0; i < N - 1; i++) {
		for (int k = N - 1; k > i; k--)
			printf("*");
		for (int j = 0; j <=i; j++)
			printf(" ");
		for (int j = 0; j <=i; j++)
			printf(" ");
		for (int k = N - 1; k > i; k--)
			printf("*");
		printf("\n");
	}
}