#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string week[] = { "SUN","MON","TUE'","WED","THUR","FRI","SAT" };

	int M, D;
	cin >> M >> D;

	int d = D;

	for (int i = 1; i < M; i++) {
		d += day[i - 1];
	}
	cout << week[d % 7] << "\n";

}