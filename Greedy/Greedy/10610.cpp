#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	vector<int> v;
	string input;
	long long sum = 0;
	bool flag = false;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		int tmp = input[i] - '0';
		if (tmp == 0)
			flag = true;
		sum += tmp;
		v.push_back(tmp);
	}

	if (!flag || (sum % 3 != 0))
		cout << -1 << "\n";
	else {
		sort(v.begin(), v.end());
		for (int i = v.size() - 1; i >= 0; i--)
			cout << v[i];
	}
	cout << "\n";
}