//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//#define MAX 1000001
//int num[MAX];
//int N;
//
//void Bubblesort(){
//	for (int i = 0; i < N; i++) {
//		for (int j = i + 1; j < N; j++) {
//			if (num[i] > num[j]) {
//				int tmp = num[i];
//				num[i] = num[j];
//				num[j] = tmp;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//	Bubblesort();
//	for (int i = 0; i < N; i++)
//		printf("%d\n", num[i]);
//}

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> nums;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}

	sort(nums.begin(), nums.end());
	for (int i = 0; i < N; i++)
		printf("%d\n", nums[i]);
}