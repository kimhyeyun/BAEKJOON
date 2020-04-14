#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 201
#define mod 1000000000

//1개의 수로 만드는 경우는 하나이고
//N을 K개로 만들 때 K-1개로 만든 0~N-1의 값들을 모두 더한값임.

int main() {
	int N, K;
	long long DP[MAX][MAX] = { 0, };

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
		DP[1][i] = 1;

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++)
				DP[i][j] += (DP[i - 1][k]);
			DP[i][j] %= mod;
		}

	}

	printf("%lld\n", DP[K][N]);


}