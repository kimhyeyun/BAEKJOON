#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int N;
	
	cin >> N;
	int* P = new int[N];

	for (int i = 0; i < N; i++)
		cin >> P[i];

	sort(P, P + N);

	for (int i = 1; i < N; i++) {
		P[i] = P[i] + P[i - 1];
	}
	
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += P[i];
	}

	cout << answer << "\n";
}