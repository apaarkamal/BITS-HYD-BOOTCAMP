#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	int a[n + 1][m + 1], p[n + 1][m + 1];

	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch;
			cin >> ch;
			a[i][j] = (ch == '#');
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
			// cout << p[i][j] << " ";
		}
		// cout << '\n';
	}

	int raju_mango = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			int sum1 = p[i - 1][j - 1];
			int sum2 = p[i - 1][m] - p[i - 1][j - 1];
			int sum3 = p[n][j - 1] - p[i - 1][j - 1];
			int sum4 = p[n][m] - sum3 - sum2 - sum1;

			raju_mango = max(raju_mango,
			                 min({sum1, sum2, sum3, sum4}));

		}
	}

	cout << raju_mango;




	return 0;
}