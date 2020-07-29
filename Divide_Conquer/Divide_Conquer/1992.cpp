#include<iostream>
using namespace std;

#define MAX 65

int** video;

void quadTree(int N, int start_x, int start_y) {
	
	int half = N / 2;
	for (int i = start_x; i < start_x + N; i++) {
		for (int j = start_y; j < start_y + N; j++) {
			if (video[start_x][start_y] != video[i][j]) {
				cout << "(";
				for (int a = 0; a < 2; a ++) {
					for (int b = 0; b < 2; b++) {
						if (N == 1) {
							cout << video[start_x][start_y];
							return;
						}
						quadTree(half, start_x + half * a, start_y + half * b);
					}
				}
				cout << ")";
				return;
			}
		}
	}

	cout << video[start_x][start_y];
	return;

}

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int N;
	string num;
	cin >> N;
	video = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++)
		video[i] = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < N; j++) {
			video[i][j] = num[i] - '0';
		}
	}

	quadTree(N, 0, 0);
}