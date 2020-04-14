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
			DP[i] = (DP[i - 1] + DP[i]) % mod; //각 하나씩 경우
		
		if (i == 1)//i가 1이면 i-2에서 오류
			continue;

		int tmp = Amho[i] + Amho[i - 1] * 10;
		if (tmp >= 10 && tmp <= 26)
			DP[i] = (DP[i - 2] + DP[i]) % mod; 
		//앞에꺼랑 두자리가 되는경우를 앞에 1자리씩 한 경우랑 더해줌 

	}

	printf("%d\n", DP[len]);

}