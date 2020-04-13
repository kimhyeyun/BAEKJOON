#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 10001

//��Ģ �� �� �̻� �������� ���� �� ����
int main() {
	int N;
	int wine[MAX] = { 0, }; //�������� �� ����
	int dp[MAX] = { 0, }; //�ִ�� ����

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int j = 3; j <= N; j++) {
		dp[j] = max((wine[j] + dp[j - 2]), (wine[j] + wine[j - 1] + dp[j - 3]));
		dp[j] = max(dp[j], dp[j - 1]); //���� ���� �ȸ��� ���ɼ��� �ֱ� ����
	}

	int answer = 0;

	for (int i = 1; i <= N; i++)
		answer = max(answer, dp[i]);

	printf("%d\n", answer);
	
}