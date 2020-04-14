#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 31
int N;
int wall[MAX] = { 0, };

int solution() {
	if (N % 2 == 1)
		return 0;

	wall[0] = 1;
	wall[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		wall[i] = wall[i - 2] * 3;
		for (int j = 4; j <= i; j += 2)
			wall[i] += (wall[i-j] * 2); //4부터는 고유 모양이 2개씩 있음 
	}
	return wall[N];

}

int main() {
	cin >> N;
	int answer = solution();
	printf("%d\n", answer);
}