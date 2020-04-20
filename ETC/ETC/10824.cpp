#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main() {
	long long A, B, C, D;
	cin >> A >> B >> C >> D;
	string a = to_string(A) + to_string(B);
	string b = to_string(C) + to_string(D);
	long long result1 = stoll(a);
	long long result2 = stoll(b);

	printf("%lld\n", result1 + result2);
}
