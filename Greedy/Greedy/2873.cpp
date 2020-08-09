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

	if (R % 2) { //���ΰ� Ȧ��
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

	//���ΰ� ¦��, ���ΰ� Ȧ��
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

	//���ΰ� ¦��, ���ΰ� ¦��
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

		//������ ���� ��ǥ�� ����������
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
		//������ ���� ��ǥ�� �밢�� �Ʒ����� �̵�
		int newC = y;
		for (int i = 0; i < newC; i++) {
			if (i % 2 == 0)
				result += "DR";
			else
				result += "UR";
		}

		//������ ���ƾ� �� ��ǥ�� �ֿ�������
		for (int i = newC; i < C - 1; i++) {
			if (i % 2 == 0)
				result += "RD";
			else
				result += "RU";
		}

		//��������~
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