#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;

int divisors[N];

void seive() {
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			divisors[j]++;
		}
		// cout << i << " -> ";
		// for (int j = 0; j < 30; j++) {
		// 	cout << divisors[j] << " ";
		// } cout << '\n' << '\n';
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << divisors[n] << '\n';
	}




	return 0;
}