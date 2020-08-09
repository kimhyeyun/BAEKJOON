#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

typedef struct meeting {
	int start;
	int fin;
};

meeting* arr[100001];
int total = 0;
int now_num = 0;

bool cmp_s(meeting* a, meeting* b) {
	return a->start < b->start;
}

bool cmp_f(meeting* a, meeting* b) {
	return a->fin < b->fin;
}

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int total_num;
	cin >> total_num;

	for (int i = 0; i < total_num; i++) {
		int start, end;
		cin >> start >> end;
		arr[i] = (meeting*)malloc(sizeof(meeting));
		arr[i]->start = start;
		arr[i]->fin = end;
	}

	sort(arr, arr + total_num, cmp_f);

	for (int i = 0; i < total_num; i++) {
		if (now_num <= arr[i]->start) {
			int j = i + 1;
			while ((j < total_num) && (arr[i]->fin == arr[j]->fin))
				j++;

			sort(arr + i, arr + j, cmp_s);

			now_num = arr[i]->fin;
			total++;
		}
	}

	cout << total << "\n";
}