#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;

int tot[N], pr[N];

void seive() {
	// tot[i]=i;
	iota(tot, tot + N, 0);

	for (int i = 2; i < N; i++) {
		if (pr[i] == 0) {
			// cout << i << '\n';
			for (int j = i; j < N; j += i) {

				// totient
				tot[j] *= (i - 1);
				tot[j] /= i;

				// prime check
				pr[j]++;

			}
		}
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
		cout << tot[n] << '\n';
	}




	return 0;
}