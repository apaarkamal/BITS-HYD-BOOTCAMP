#include<bits/stdc++.h>

using namespace std;

int kadane(int a[], int n) {
	int max_end = INT_MIN, max_ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		max_end = max(max_end + a[i], 0);
		max_ans = max(max_ans, max_end);
	}
	return max_ans;
}

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
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			p[i][j] = p[i][j - 1] + a[i][j];
			// cout << p[i][j] << " ";
		}
		// cout << '\n';
	}

	int max_subarray_sum = INT_MIN;

	for (int j = 1; j <= m; j++) {
		for (int k = j; k <= m; k++) {
			int a_sub[n + 1];
			for (int i = 1; i <= n; i++) {
				a_sub[i] = p[i][k] - p[i][j - 1];
			}

			max_subarray_sum = max(max_subarray_sum, kadane(a_sub, n));
		}
	}

	cout << max_subarray_sum;




	return 0;
}