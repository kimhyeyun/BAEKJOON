#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair < pair<int, int>, pair<int, string> >& a, pair < pair<int, int>, pair<int, string> >& b) {
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			if (a.second.first == b.second.first) {
				return a.second.second < b.second.second;
			}
			return a.second.first > b.second.first;
		}
		return a.first.second < b.first.second;
	}
	return a.first.first > b.first.first;

}

int main() {
	vector< pair < pair<int, int>, pair<int, string> > > students;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string name;
		int guku;
		int english;
		int math;
		cin >> name >> guku >> english >> math;

		students.push_back(make_pair(make_pair(guku, english), make_pair(math, name)));
	}

	sort(students.begin(), students.end(), comp);

	for (int i = 0; i < N; i++)
		cout<< students[i].second.second << "\n";
}