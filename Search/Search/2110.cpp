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

		//�ϳ��ϳ� �Ǵ� �ٸ鼭 �������� ���� ���� ���� mid�̻��� ��쿡�� ��ġ����
		for (int i = 1; i< N; i++) {
			//���� ��ġ�� ���� ��ġ�� �������� ��ġ�� ������ mid���� ũ�ٸ�
			if (wifi.at(i) - wifi.at(befor_set_idx) >= mid) {
				befor_set_idx = i;
				set_num++;
			}
		}

		//��� �ε����� Ȯ���ϸ� ������ �Է¹��� c���� ū�� Ȯ����
		//c���� ũ�� ������ �ִ밪�� �ǰ�, left�� �����Ͽ� �� ū ���� Ž���ϰ� �ݴ��� ��� right�� ����
		if (set_num >= C)
			left = mid + 1;
		else
			right = mid - 1;

		//������ ��ġ ������� �� ũ�� ������ ��ü��
		if (answer < mid && set_num >= C)
			answer = mid;
	}
	printf("%d\n", answer);

}