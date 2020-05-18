#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> wifi;
	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		wifi.push_back(x);
	}
	sort(wifi.begin(), wifi.end());

	int left = wifi.front();
	int right = wifi.back();
	int answer = -1;

	while (left <= right) {
		int mid = (right + left) / 2;
		int befor_set_idx = 0;
		int set_num = 1;

		//하나하나 건더 뛰면서 공유기의 값이 현재 값의 mid이상인 경우에만 설치가능
		for (int i = 1; i< N; i++) {
			//현재 위치와 직전 설치한 공유기의 위치의 간격이 mid보다 크다면
			if (wifi.at(i) - wifi.at(befor_set_idx) >= mid) {
				befor_set_idx = i;
				set_num++;
			}
		}

		//모든 인덱스를 확인하면 갯수가 입력받은 c보다 큰지 확인함
		//c보다 크면 현재의 최대값이 되고, left를 변경하여 더 큰 값을 탐색하고 반대인 경우 right를 변경
		if (set_num >= C)
			left = mid + 1;
		else
			right = mid - 1;

		//현재의 설치 대수보다 더 크면 정답을 교체함
		if (answer < mid && set_num >= C)
			answer = mid;
	}
	printf("%d\n", answer);

}