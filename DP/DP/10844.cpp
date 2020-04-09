#include<iostream>
#include<stdio.h>
using namespace std;

#define mod 1000000000


int main() {
	int N;
	int stairs[101][10]; //앞의 칸은 숫자의 길이, 뒤는 마지막 숫자
	int sum = 0;
	cin >> N;

	for (int i = 0; i < 10; i++)
		stairs[1][i] = 1; //1자리 숫자는 1임
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) //마지막이 0 일때는 
				stairs[i][0] = stairs[i - 1][1] % mod; //앞에 무조건 1 뿐이기 때문에 i-1 길이의 마지막 수가 1일때의 값이랑 동일
			else if (j == 9) //마지막이 9일때는
				stairs[i][9] = stairs[i - 1][8] % mod; //앞이 무조건 8 뿐이기 때문에 i-1 길이의 마지막 수가 8일때의 값이랑 동일
			else //나머지
				stairs[i][j] = (stairs[i - 1][j - 1] + stairs[i - 1][j + 1]) % mod; //앞에 +1,-1의 수가 오는 경우가 있어서 i-1길이의 마지막수가 -1,+1 일때의 값의 합
		}
	}
	for (int k = 1; k < 10; k++) {
		sum += (stairs[N][k]%mod);
	}
	printf("%d\n", sum);
}