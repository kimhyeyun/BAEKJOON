#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main() {
	stack<char> pipe;
	int answer = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			pipe.push(str[i]);
		else {
			pipe.pop();
			if (str[i-1] == '(')
				answer += pipe.size();
			else
				answer += 1;
		}
	}
	printf("%d\n", answer);
		
}