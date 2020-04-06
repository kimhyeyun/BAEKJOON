#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	int sum = 0;
	int *a=new int[T];
	for (int i = 0; i < T; i++) {
		scanf_s("%1d", &a[i]);
		sum += a[i];
	}
	printf("%d\n", sum);

}