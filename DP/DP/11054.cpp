#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 1001

int main() {
	int N;
	int DPI[MAX] = { 0, };
	int DPD[MAX] = { 0, };
	int A[MAX] = { 0, };
	int answer = 0;
	
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> A[i];
	
	//�տ��� �ڷ� �����ϴ� �ִ�
	for (int i = 1; i <= N; i++) {
		DPI[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[i] > A[j] && DPI[i] <= DPI[j])
				DPI[i] = DPI[j] + 1;
	} 
	//�ڿ��� ������ �����ϴ� �ִ�
	for (int i = N; i > 0;i--) {
		DPD[i] = 1;
		for (int j = N; j > i; j--) {
			if (A[i] > A[j] && DPD[i] <= DPD[j])
				DPD[i] = DPD[j] + 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		answer = max(answer, DPD[i] + DPI[i]);
	}
	
	//����� ��ġ�� ������ -1
	printf("%d\n", answer - 1);
}
