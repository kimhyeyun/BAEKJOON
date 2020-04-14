#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 5001
#define mod 1000000

int Amho[MAX] = { 0, };
int DP[MAX] = { 0, };

int main() {
	string amhostr;
	cin >> amhostr;

	int len = amhostr.length();

	if (len == 0 && amhostr[0] == '0') {
		printf("0\n");
		return 0;
	}

	for (int i = 1; i <= len; i++)
		Amho[i] = amhostr[i-1] - '0';
		
	DP[0] = 1;

	for (int i = 1; i <= len; i++) {
		if (Amho[i] >= 1 && Amho[i] <= 9)
			DP[i] = (DP[i - 1] + DP[i]) % mod; //�� �ϳ��� ���
		
		if (i == 1)//i�� 1�̸� i-2���� ����
			continue;

		int tmp = Amho[i] + Amho[i - 1] * 10;
		if (tmp >= 10 && tmp <= 26)
			DP[i] = (DP[i - 2] + DP[i]) % mod; 
		//�տ����� ���ڸ��� �Ǵ°�츦 �տ� 1�ڸ��� �� ���� ������ 

	}

	printf("%d\n", DP[len]);

}