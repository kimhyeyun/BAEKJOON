#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main() {
	string octal;
	cin >> octal;
	string binary = "";

	for (int i = 0; i < octal.length();i++) {
		if (octal == "0") {
			binary = "0";
			break;
		}
		switch (octal[i]) {
		case '0':
			binary += "000";
			break;
		case'1':
			if (i == 0) {
				binary += "1";
				break;
			}
			binary += "001";
			break;
		case'2':
			if (i == 0) {
				binary += "10";
				break;
			}
			binary += "010";
			break;
		case'3':
			if (i == 0) {
				binary += "11";
				break;
			}
			binary += "011";
			break;
		case'4':
			binary += "100";
			break;
		case'5':
			binary += "101";
			break;
		case'6':
			binary += "110";
			break;
		case'7':
			binary += "111";
			break;
		}
	}
	cout << binary;
}