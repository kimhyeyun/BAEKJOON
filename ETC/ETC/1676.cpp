#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int two = 0;
	int five = 0;
	
	for (int i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (int i = 5; i <= n; i *= 5)
		five += n / i;
	printf("%d\n", (two < five) ? two : five);
}