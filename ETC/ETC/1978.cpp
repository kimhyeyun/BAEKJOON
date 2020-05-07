#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main() {
	int N, cnt;
	int answer = 0;
	vector<int> nums;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		nums.push_back(x);
	}
	for (int i = 0; i < nums.size(); i++) {
		cnt = 0;
		for(int j=2;j<nums[i];j++){
			if (nums[i] % j == 0)
				cnt++;
		}
		if (cnt == 0) {
			answer++;
			if (nums[i] == 1)
				answer--;
		}
			
	}
	printf("%d\n", answer);
}