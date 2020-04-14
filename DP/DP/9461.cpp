#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 101

int main() {
	int N, T;
	long long triangle[MAX] = { 0, };  //변수 타입 조심!
	triangle[1] = 1;
	triangle[2] = 1;
	triangle[3] = 1;
	triangle[4] = 2;
	triangle[5] = 2;
	triangle[6] = 3;

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 7; i <= N; i++) {
			triangle[i] = triangle[i - 3] + triangle[i - 2];
		}
		printf("%lld\n", triangle[N]);
	}
}