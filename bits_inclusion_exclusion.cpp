#include<bits/stdc++.h>
#define int long long int

using namespace std;

void solve(int n) {

	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

	int ans = 0;

	for (int i = 1; i < (1 << 8); i++) {
		int lcm = 1;
		for (int bit = 0; bit < 8; bit++) {
			if ((i >> bit) & 1) {
				// cout << primes[bit] << " ";
				lcm *= primes[bit];
			}
		}

		if (__builtin_popcount(i) & 1) {
			// odd size set than add in answer
			// inclusion
			ans += (n / lcm);
		}
		else {
			// even size set than subract in answer
			// exclusion
			ans -= (n / lcm);
		}


		// cout << '\n';
	}

	cout << ans << '\n';
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int i = 10; i <= 1e17; i *= 10) {
		solve(i);
	}

	return 0;
}