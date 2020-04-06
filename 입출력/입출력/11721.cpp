#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	string str;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		printf("%c", str[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
}