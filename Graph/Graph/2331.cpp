#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int check[236197];
int len = 1;
int A, P;

int calculate(int num) {
	int result = 0;
	while (num > 0) {
		int n = num % 10;
		result += pow((double)n, (double)P);
		num /= 10;
	}
	return result;
}

int DFS(int start) {
	check[start] = len;
	if (check[calculate(start)] != 0)
		return check[calculate(start)] - 1;
	else {
		len++;
		return DFS(calculate(start));
	}
}

int main(){
	cin >> A >> P;
	printf("%d\n", DFS(A));
}