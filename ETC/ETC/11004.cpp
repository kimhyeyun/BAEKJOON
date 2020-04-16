#include<iostream>
#include<stdio.h>
using namespace std;

void Swap(int As[], int a, int b) {
	int tmp = As[a];
	As[a] = As[b];
	As[b] = tmp;
}

int Partition(int As[], int left, int right) {
	//�⺻������ quicksort�� pivot ���� �� ��ȯ������ ����
	//pivot�� ���� ������ �ε����� ����
	int pivot = As[left];
	int low = left + 1;
	int high = right;
	while (low <= high) { //�����Ǳ� ������ �ݺ�
		while (low <= right && As[low] <= pivot) //pivot���� ū ���� ã�� ����
			low++; 
		while (high >= (left + 1) && As[high] >= pivot)
			high--;
		if (low <= high) //�������� ���� �����̸� ���� ���� ����
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
		return QuickSearch(As, left, pivot - 1, k); //���� ���� ����
	else
		return QuickSearch(As, pivot + 1, right, k);//������ ���� ����
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



