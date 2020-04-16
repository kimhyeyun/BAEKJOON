#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	vector<pair<int,int> > location;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		location.push_back(make_pair(x, y));
	}
	sort(location.begin(), location.end(), comp);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", location[i].first, location[i].second);
	

}