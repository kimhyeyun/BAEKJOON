#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 1000001

int N;
int Array[MAX] = { 0, };
int answer[MAX] = { 0, };
int m = -1000; //가장 작은값이 이거, 비교하여 최대값을 저장하는 변수 

//
int solution() {
	for (int i = 0; i < N; i++) {
		answer[i] = max((answer[i - 1] + Array[i]), Array[i]); //앞과 더한 값이 더크면 더해서 저장, 아니면 자기값 저장
		m = max(m, answer[i]); //배열의 최대값
	}
	return m;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Array[i];
	int a = solution();
	printf("%d\n", a);
}