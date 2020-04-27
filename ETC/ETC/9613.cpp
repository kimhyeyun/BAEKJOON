#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int gcd(vector<int> a) {
	int result = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			int x = a[i];
			int y = a[j];
			while (y != 0) {
				int r = x % y;
				x = y;
				y = r;
			}
			result += x;
		}
	}
	return result;
}

int main() {
	vector<int> num;
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			num.push_back(x);
		}
		printf("%d\n", gcd(num));
		num.clear();
	}
}