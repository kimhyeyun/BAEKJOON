#include<iostream>
#include<stdio.h>
using namespace std;

void Swap(int As[], int a, int b) {
	int tmp = As[a];
	As[a] = As[b];
	As[b] = tmp;
}

int Partition(int As[], int left, int right) {
	//기본적으로 quicksort의 pivot 선정 후 교환과정과 동일
	//pivot은 가장 왼쪽의 인덱스로 결정
	int pivot = As[left];
	int low = left + 1;
	int high = right;
	while (low <= high) { //교차되기 전까지 반복
		while (low <= right && As[low] <= pivot) //pivot보다 큰 값을 찾는 과정
			low++; 
		while (high >= (left + 1) && As[high] >= pivot)
			high--;
		if (low <= high) //교차되지 않은 상태이면 스왑 과정 실행
			Swap(As, low, high);
	}
	Swap(As, left, high);
	return high;
}

int QuickSearch(int As[], int left ,int right, int k) {
	int pivot = Partition(As, left, right);
	if (pivot == k)
		return As[pivot];
	else if (pivot > k)
		return QuickSearch(As, left, pivot - 1, k); //왼쪽 영역 정렬
	else
		return QuickSearch(As, pivot + 1, right, k);//오른쪽 영역 정렬
	}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	
	int* As = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &As[i]);

	printf("%d", QuickSearch(As, 0, N - 1, K - 1));
}

#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000000];
int main() {
	int n, k;
	cin >> n >> k;
	int num = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	cout << arr[k - 1] << endl;
}



