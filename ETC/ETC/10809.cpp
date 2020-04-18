#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int alphabet[26];
	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (alphabet[str.at(i) - 'a'] == -1)
			alphabet[str.at(i) - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);
	printf("\n");
}