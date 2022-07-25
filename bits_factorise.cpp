#include<bits/stdc++.h>
#define int long long int

using namespace std;

vector<pair<int, int>> factorise(int n) {
	vector<pair<int, int>> res;
	// sqrt(n)
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			// i is a prime number
			int q = 0;
			while (n % i == 0) {
				n /= i;
				q++;
			}
			res.push_back({i, q});
		}
	}
	// is n does not reduce to 1 => n is prime
	if (n > 1) {
		res.push_back({n, 1});
	}
	return res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int n = 100;

	vector<pair<int, int>> prime_factors = factorise(n);

	for (auto x : prime_factors) {
		cout << x.first << " " << x.second << '\n';
	}

	return 0;
}