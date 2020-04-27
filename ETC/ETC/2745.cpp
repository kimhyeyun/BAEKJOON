#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main() {
	string str;
	int B;
	cin >> str >> B;

	int tmp;
	int result = 0;
	int len = str.length();
	for (int i = 0; i <str.length(); i++) {
		if (str[i] < 58)
			tmp = str[i] - 48;
		else
			tmp = str[i] - 65 + 10;

		result += (tmp * pow(B, len - i - 1));
	}

	printf("%d\n", result);
}