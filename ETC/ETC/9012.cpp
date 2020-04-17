#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main() {
	int test_case;
	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {
		stack<char> stk;
		bool flag = true;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				stk.push(str[j]);
			}
			else {
				if (stk.empty())
					flag = false;
				else {
					stk.pop();
				}
			}
		}
		if (!stk.empty())
			flag = false;

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}