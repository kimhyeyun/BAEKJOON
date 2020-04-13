#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 10001

//규칙 세 잔 이상 연속으로 마실 수 없음
int main() {
	int N;
	int wine[MAX] = { 0, }; //포도주의 양 저장
	int dp[MAX] = { 0, }; //최대양 저장

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int j = 3; j <= N; j++) {
		dp[j] = max((wine[j] + dp[j - 2]), (wine[j] + wine[j - 1] + dp[j - 3]));
		dp[j] = max(dp[j], dp[j - 1]); //현재 잔을 안마실 가능성도 있기 때문
	}

	int answer = 0;

	for (int i = 1; i <= N; i++)
		answer = max(answer, dp[i]);

	printf("%d\n", answer);
	
}