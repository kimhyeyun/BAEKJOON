#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int N, money;
vector<int> v;

int minCoin() {
	int cnt = 0;

	for (int i = v.size() - 1; i >= 0; i--) {
		while (money - v[i] >= 0) {
			money -= v[i];
			cnt++;
			if (!money)
				break;
		}
	}
	if (money)
		return 0;
	return cnt;
}

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	cin >> N >> money;

	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		v.push_back(value);
	}
	cout << minCoin() << "\n";
	
}