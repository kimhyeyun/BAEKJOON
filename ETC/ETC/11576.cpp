#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main() {
	string str;
	int A, B;
	int M;
	vector<int> nums;
	cin >> A >> B;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		nums.push_back(x);
	}
	//A진수->10진수 
	int answ = 0;
	for (int i = 0; i < M; i++)
		answ = answ * A + nums[i];

	//10진수->B진수
	vector<int> ans;
	while (answ != 0) {
		ans.push_back(answ % B);
		answ /= B;
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		printf("%d ", ans[i]);
	printf("\n");
}