#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 201
#define mod 1000000000

//1���� ���� ����� ���� �ϳ��̰�
//N�� K���� ���� �� K-1���� ���� 0~N-1�� ������ ��� ���Ѱ���.

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