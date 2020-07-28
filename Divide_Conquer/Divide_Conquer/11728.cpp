#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//맞긴 햇는데 다시!
//int main() {
//	cin.tie(0);
//	std::ios_base::sync_with_stdio(false);
//	vector<int> a;
//	int N, M;
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		int x;
//		cin >> x;
//		a.push_back(x);
//	}
//	for (int i = 0; i < M; i++) {
//		int x;
//		cin >> x;
//		a.push_back(x);
//	}
//
//	sort(a.begin(), a.end());
//	for (int i = 0; i < a.size(); i++)
//		cout << a[i] << " ";
//	cout << "\n";
//}

#define MAX 1000001
int N, M;
int A[MAX], B[MAX], ans[MAX];

void merge() {
	int i = 0, j = 0, k = 0;

	while (i < N && j < M) {
		if (A[i] <= B[j])
			ans[k++] = A[i++];
		else
			ans[k++] = B[j++];
	}

	while (i < N)
		ans[k++] = A[i++];
	while (j < M)
		ans[k++] = B[j++];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];

	int length = N + M;

	merge();

	for (int i = 0; i < length; i++)
		cout << ans[i] << " ";

	cout << "\n";
		

	
}