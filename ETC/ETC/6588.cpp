#include<iostream>
#include<stdio.h>
#include "6588.h"
using namespace std;

#define MAX 100001


int isNotPrime[MAX];

void goldvach() {
	for (int i = 2; i * i < MAX; i++) {
		if (!isNotPrime[i])
			for (int j = i * i; j < MAX; j += i)
				isNotPrime[j] = 1;
		isNotPrime[1] = 1;
	}
}
int main() {
	goldvach();

	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		bool flag = false;
		for (int i = 3; i <= n; i += 2) {
			if (!isNotPrime[i] && !isNotPrime[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				flag = true;
				break;
			}
		}
		if (!flag)
			printf("Goldbach's conjecture is wrong.\n");
	}
	
}