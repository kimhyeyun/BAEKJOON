#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);


	vector<int> arr;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	long ans = 0;

	sort(arr.begin(), arr.end());

	int left = 0;
	int right = N - 1;

	// negative
	for (; left < right; left += 2) {
		if (arr[left] < 1 && arr[left + 1] < 1)
			ans += arr[left] * arr[left + 1];
		else
			break;
	}

	//positive
	for (; right > 0; right -= 2) {
		if (arr[right] > 1 && arr[right - 1])
			ans += arr[right] * arr[right - 1];
		else
			break;
	}

	for (; right >= left; right--)
		ans += arr[right];

	cout << ans << "\n";
}