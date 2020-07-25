#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	vector<int> sanggen;
	int N, M, x;
	cin >> N;

	while (N--) {
		cin >> x;
		sanggen.push_back(x);
	}
	
	sort(sanggen.begin(),sanggen.end());

	cin >> M;
	while (M--) {
		cin >> x;

		int left = 0, right = N - 1;
		bool search = false;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (sanggen[mid] == x) {
				search = true;
				break;
			}
			else if (sanggen[mid] < x)
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (search)
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	cout << "\n";
}