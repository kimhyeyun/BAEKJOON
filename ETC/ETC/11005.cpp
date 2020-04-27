#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main() {
	int N, B;
	stack<int> stk;
	
	cin >> N >> B;

	while (N!=0) {
		stk.push(N % B);
		N /= B;
	}
	while (!stk.empty()) {
		if (stk.top() < 10)
			printf("%d", stk.top());
		else
			printf("%c", stk.top() + 55);
		stk.pop();
	}
	printf("\n");

}