#include<iostream>
#include<stdio.h>
using namespace std;

int K, N;
int lan[10000];

bool check(int mid) {
	int cnt = 0;
	for (int i = 0; i < K; i++)
		cnt += lan[i] / mid;

	return cnt >= N;
}

int main() {
	cin >> K >> N;

	int max = 0;
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		if (max < lan[i])
			max = lan[i];
	}
	long long left = 1, right = max;
	int ans = 0;
	
	while (left <= right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			if (mid > ans)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	printf("%d\n", ans);
}