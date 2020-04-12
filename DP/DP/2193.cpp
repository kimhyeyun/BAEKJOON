#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int N;
	int pinaryNum[91];
	cin >> N;

	pinaryNum[1] = 1;
	pinaryNum[2] = 1;
	pinaryNum[3] = 2;

	for (int i = 4; i <= N; i++)
		pinaryNum[i] = pinaryNum[i - 1] + pinaryNum[i - 2];

	printf("%d\n", pinaryNum[N]);
}