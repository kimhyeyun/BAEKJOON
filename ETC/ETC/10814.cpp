#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}
int main() {
	vector<pair<int, string> > members;

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		members.push_back(make_pair(age, name));
	}

	//stable_sort : ���� �� ���ϰ��� ���� ������ ��������
	stable_sort(members.begin(), members.end(), comp);
	for (int i = 0; i < N; i++)
		cout<< members[i].first << " " << members[i].second << "\n";
}