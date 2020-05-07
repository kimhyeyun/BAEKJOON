#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

void getCheck(int M, int N) {
	int* arr;
	arr = (int*)malloc(sizeof(int) *(N+1) );

	for (int i = M; i <= N; i++)
		arr[i] = i;

	for (int i = 2; i <=N ; i ++ ) {
		if (arr[i] == 0)
			continue;
		for (int j = 2 * i; j <= N; j += i)
			arr[j] = 0;
	}
	for (int i = M; i <= N; i++)
		if (arr[i] != 0)
			printf("%d\n", i);
}

int main() {
	int M, N;
	int answer;
	cin >> M >> N;
	getCheck(M, N);
}