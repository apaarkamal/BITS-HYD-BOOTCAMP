#include<bits/stdc++.h>

using namespace std;

int cnt = 0;

const int N = 100;
int memo[N];

int f(int n) {
	cnt++;
	if (n <= 1) return n;

	// memoise
	if (memo[n] != -1) return memo[n];

	return memo[n] = f(n - 1) + f(n - 2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// 21891

	memset(memo, -1, sizeof(memo));

	for (int i = 0; i <= 20; i++) {
		cnt = 0;
	}

	f(20);
	// cout << i << " " << cnt << '\n';
	cout << cnt;


	int fib[N];
	fib[0] = 0; fib[1] = 1;
	// tabulation
	for (int i = 2; i <= 20; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}













	return 0;

}