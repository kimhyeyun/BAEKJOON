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
	
	//앞에서 뒤로 증가하는 최댓값
	for (int i = 1; i <= N; i++) {
		DPI[i] = 1;
		for (int j = 1; j < i; j++)
			if (A[i] > A[j] && DPI[i] <= DPI[j])
				DPI[i] = DPI[j] + 1;
	} 
	//뒤에서 앞으로 증가하는 최댓값
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
	
	//가운데는 겹치기 때문에 -1
	printf("%d\n", answer - 1);
}
