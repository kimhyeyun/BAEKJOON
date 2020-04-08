#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int x;
	cin >> x;
	int DP[1000001];
	
	DP[1] = 0;

	for (int i = 2; i <= x; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0) 
			DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0)
			DP[i] = min(DP[i], DP[i / 2] + 1);
	}

	printf("%d\n", DP[x]);
}