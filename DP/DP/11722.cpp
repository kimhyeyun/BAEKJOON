#include<iostream>
#include<stdio.h>
#include<algorithm>    
using namespace std;

#define MAX 1001

int main() {
	int N;
	int A[MAX] = { 0, };
	int DP[MAX] = { 0, };
	int answer = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];


	for (int i = 1; i <= N; i++) {
		DP[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[i] < A[j] && DP[i] <= DP[j])
				DP[i] = DP[j] + 1;
	}
	for (int i = 1; i <= N; i++)
		answer = max(answer, DP[i]);
	printf("%d\n", answer);
}