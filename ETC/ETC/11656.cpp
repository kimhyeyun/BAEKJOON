#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.length();

	string* sub = new string[len];

	for (int i = 0; i < len; i++) {
		sub[i] =  str.substr(i, len);
	}

	sort(sub, sub + len);

	for (int i = 0; i < len; i++)
		cout << sub[i] << '\n';
}