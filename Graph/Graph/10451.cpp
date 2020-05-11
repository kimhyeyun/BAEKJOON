#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int N;
int ans;
vector<int> arr[1001];
bool visited[1001];
bool recur[1001];

bool DFS(int start) {
	visited[start] = true;
	recur[start] = true;

	for (int i = 0; i < arr[start].size(); i++) {
		int b = arr[start][i];
		if (!visited[b] && DFS(b)) {
			//b�� �湮���°� �ƴϰ�, �ٽ� b�湮�� ���� Ȯ�� �� true �� cycle
			return true;
		}
		else if (recur[b])
			return true; //b�� �̹� �湮�� ���¸� cycle
		recur[start] = false;
		return false;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N;
		for (int i = 0; i <= N; i++) {
			arr[i].clear();
			visited[i] = false;
			recur[i] = false;
		}

		for (int i = 1; i <= N; i++) {
			int x; cin >> x;
			arr[i].push_back(x);
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				bool flag = DFS(i);
				if (flag)
					ans++;
			}
		}
		printf("%d\n", ans);
	
	}
}