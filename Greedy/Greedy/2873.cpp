#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int Coaster[1000][1000];
	int R, C;
	string result;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> Coaster[i][j];
	}

	if (R % 2) { //세로가 홀수
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					result += 'R';
				else
					result += 'L';
			}
			if (i != R - 1)
				result += 'D';
		}
	}

	//세로가 짝수, 가로가 홀수
	else if (!(R % 2) && (C % 2)) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R - 1; j++) {
				if (i % 2 == 0)
					result += 'D';
				else
					result += 'U';
			}
			if (i != C - 1)
				result += 'R';
		}
	}

	//세로가 짝수, 가로가 짝수
	else if (!(R % 2) && !(C % 2)) {
		int x,y;
		int minhappy = 987654321;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if ((i + j) % 2  && minhappy > Coaster[i][j]) {
					minhappy = Coaster[i][j];
					x = i, y = j;
				}
			}
		}

		//지나지 않을 좌표의 최좌측가기
		int newR = x % 2 ? x - 1 : x;
		for (int i = 0; i < newR; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					result += 'R';
				else
					result += 'L';
			}
			result += 'D';
		}
		//지나지 않을 좌표의 대각선 아래까지 이동
		int newC = y;
		for (int i = 0; i < newC; i++) {
			if (i % 2 == 0)
				result += "DR";
			else
				result += "UR";
		}

		//지나지 말아야 할 좌표의 최우측가기
		for (int i = newC; i < C - 1; i++) {
			if (i % 2 == 0)
				result += "RD";
			else
				result += "RU";
		}

		//목적지로~
		if (x % 2 == 0)
			newR = R - (x + 2);
		else
			newR = R - (x + 1);

		for (int i = 0; i < newR; i++) {
			result += 'D';
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					result += 'L';
				else
					result += 'R';
			}
		}
	}

	cout << result << "\n";
		
}