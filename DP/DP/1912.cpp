#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 1000001

int N;
int Array[MAX] = { 0, };
int answer[MAX] = { 0, };
int m = -1000; //���� �������� �̰�, ���Ͽ� �ִ밪�� �����ϴ� ���� 

//
int solution() {
	for (int i = 0; i < N; i++) {
		answer[i] = max((answer[i - 1] + Array[i]), Array[i]); //�հ� ���� ���� ��ũ�� ���ؼ� ����, �ƴϸ� �ڱⰪ ����
		m = max(m, answer[i]); //�迭�� �ִ밪
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