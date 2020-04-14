#include<iostream>
#include<stdio.h>
#include<algorithm>    
using namespace std;

#define MAX 1001

int main() {
	int N;
	int A[MAX] = { 0, };
	int DP[MAX] = { 0, };
	int max = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];


	for (int i = 1; i <= N; i++) {
		int maxDP = 0;
		for (int j = 1; j < i; j++)
			if (A[i] > A[j])
				if (maxDP < DP[j])
					maxDP = DP[j];
		DP[i] = maxDP + A[i];
		if (max < DP[i])
			max = DP[i];
	}
	printf("%d\n", max);
}