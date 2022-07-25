#include<bits/stdc++.h>

using namespace std;

const int N = 1e6;

int prime[N];

// O(Nloglog(N))
void seive() {
	for (int i = 2; i * i < N; i++) {
		for (int j = i * i; j < N; j += i) {
			prime[j] = 1;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// precomputations
	seive();

	int t;
	cin >> t;
	// O(1)
	while (t--) {
		int n;
		cin >> n;
		// cout << prime[n] << '\n';
		cout << (prime[n] == 0 ? "prime" : "not prime") << '\n';
	}




	return 0;
}