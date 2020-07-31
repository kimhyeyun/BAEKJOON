#include<iostream>
#include<vector>
using namespace std;

long long result = 0;


void merge(vector<int> &v,int start,int end){
	int mid = (start + end) / 2;
	int left = start;
	int right = end;

	vector<int> tmp;

	if (start == end)
		return;

	merge(v,start, mid);
	merge(v,mid + 1, end);

	while (left <= mid&&right<=end) {
		if (v[left] <= v[right])
			tmp.push_back(v[left++]);
		else {
			tmp.push_back(v[right++]);
			result += (mid + 1 - left);
		}
	}

	while (left <= mid)
		tmp.push_back(v[left++]);
	while (right <= end)
		tmp.push_back(v[right++]);

	for (int i = start, j = 0; i <= end; ++i, ++j)
		v[i] = tmp[j];

}

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int N;
	vector<int> v;

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> v[i];

	merge(v, 0, N - 1);

	cout << result << "\n";
}