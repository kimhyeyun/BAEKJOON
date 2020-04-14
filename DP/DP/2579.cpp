#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 301

int N;
int stairs[MAX] = { 0, };

//연속 세개를 밟아선 안되고, 두칸이상을 건너뛸순 없음
int solution() {
	int DP[MAX] = { 0, };
	DP[0] = stairs[0]; 
	DP[1] = max(stairs[0] + stairs[1], stairs[1]);
	DP[2] = max(stairs[1] + stairs[2], stairs[0] + stairs[2]);

	for (int i = 3; i < N; i++)
		DP[i] = max(stairs[i] + stairs[i - 1] + DP[i - 3], stairs[i] + DP[i - 2]);
		//마지막은 꼭 밟아야 하는데 세칸 연속은 안되므로
	return DP[N-1];
}

 int main() {
	 cin >> N;
	 for (int i = 0; i < N; i++)
		 cin >> stairs[i];
	 int answer = solution();
	 printf("%d\n", answer);
}