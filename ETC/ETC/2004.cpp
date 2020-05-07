#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

pair<long long, long long> zeros(long long n) {
	long long two = 0, five = 0;
	for (int i = 2; i <= n; i *= 2) two += n / i;
	for (int i = 5; i <= n; i *= 5)five += n / i;
	return (pair<long long, long long>(two, five));
}

int main() {
	int n, r;
	pair<long long, long long> ans, ansr, ansnr;

	cin >> n >> r;

	ans = zeros(n);
	ansr = zeros(r);
	ansnr = zeros(n - r);


	printf("%lld\n", min((ans.first - ansr.first - ansnr.first), (ans.second - ansr.second - ansnr.second)));
}