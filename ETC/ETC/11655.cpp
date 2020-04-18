#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main() {
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (('a' <= str.at(i) && str.at(i) <= 'z')) {
			if (str.at(i) + 13 > 122)
				str.at(i) = str.at(i) + 13 - 26;
			else
				str.at(i) += 13;
		}
		else if('A'<=str.at(i)&&str.at(i)<='Z') {
			if (str.at(i) + 13 > 90)
				str.at(i) = str.at(i) + 13 - 26;
			else
				str.at(i) += 13;
		}
	}
	cout << str << endl;
}