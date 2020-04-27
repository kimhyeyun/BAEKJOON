#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;

int main() {
	string str;
	cin >> str;

	string result = "";
	int tmp = 0;
	int j = 0;

	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == '1') {
			tmp += pow(2, j);
		}
		j++;
		if (j == 3 || i == 0) {
			j = 0;
			result += to_string(tmp);
			tmp = 0;
		}
	}

	for (int i = result.length() - 1; i >= 0; i--)
		cout << result[i];
	printf("\n");
}