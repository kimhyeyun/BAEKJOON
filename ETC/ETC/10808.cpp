#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int alphabet[26] = { 0, };
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		alphabet[str.at(i) - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);
	printf("\n");
}