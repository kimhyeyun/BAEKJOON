#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main() {
	while (1) {
		int space = 0;
		int smen = 0;
		int lgen = 0;
		int num = 0;

		string str;
		getline(cin, str);
		if (str == "")
			break;
		for (int i = 0; i < str.length(); i++) {
			if (str.at(i) == ' ')
				space++;
			else if ('a' <= str.at(i) && str.at(i) <= 'z')
				smen++;
			else if ('A' <= str.at(i) && str.at(i) <= 'Z')
				lgen++;
			else if (48 <= str.at(i) && str.at(i) <= 57)
				num++;
		}
		printf("%d %d %d %d\n", smen, lgen, num, space);
	}
}