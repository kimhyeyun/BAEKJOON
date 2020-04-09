#include<iostream>
#include<stdio.h>
using namespace std;

#define mod 1000000000


int main() {
	int N;
	int stairs[101][10]; //���� ĭ�� ������ ����, �ڴ� ������ ����
	int sum = 0;
	cin >> N;

	for (int i = 0; i < 10; i++)
		stairs[1][i] = 1; //1�ڸ� ���ڴ� 1��
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) //�������� 0 �϶��� 
				stairs[i][0] = stairs[i - 1][1] % mod; //�տ� ������ 1 ���̱� ������ i-1 ������ ������ ���� 1�϶��� ���̶� ����
			else if (j == 9) //�������� 9�϶���
				stairs[i][9] = stairs[i - 1][8] % mod; //���� ������ 8 ���̱� ������ i-1 ������ ������ ���� 8�϶��� ���̶� ����
			else //������
				stairs[i][j] = (stairs[i - 1][j - 1] + stairs[i - 1][j + 1]) % mod; //�տ� +1,-1�� ���� ���� ��찡 �־ i-1������ ���������� -1,+1 �϶��� ���� ��
		}
	}
	for (int k = 1; k < 10; k++) {
		sum += (stairs[N][k]%mod);
	}
	printf("%d\n", sum);
}