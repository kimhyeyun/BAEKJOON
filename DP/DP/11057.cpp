#include<iostream>
#include<stdio.h>
using namespace std;

#define mod 10007

int main() {
	int nums[1001][10] = { 0, };
	int N;
	cin >> N;

	int answer = 0;

	for (int i = 0; i < 10; i++)
		nums[1][i] = 1; //1자리 수는 모두 한개씩

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				nums[i][j] += (nums[i - 1][k] % mod);
			}
		}
	}

	for (int i = 0; i < 10; i++)
		answer += (nums[N][i] % mod);

	printf("%d", answer % mod);
}