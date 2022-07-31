#include<bits/stdc++.h>

using namespace std;

// Time complexity - O(m*n)
// Space Complexity - O(n)

// max_cost, max_pieces
pair<int, int> rodCutting(int n, int *length, int *prices, int m) {
	if (n <= 0) {
		return {0, 0};
	}
	pair<int, int> ans = {0, 0};

	// memoise
	// if (memo[n] != -1) {
	// 	return memo[n];
	// }

	for (int i = 0; i < m; i++) {
		if (n - length[i] >= 0) {
			ans = max(ans,
			{	rodCutting(n - length[i], length, prices, m).first + prices[i],
				rodCutting(n - length[i], length, prices, m).second + 1
			});
		}
	}
	return ans;
}

// void trace_rod_cutting(int n, int *length, int *prices, int m, int memo[]) {
// 	if (n <= 0) return;

// 	for (int i = 0; i < m; i++) {
// 		if (n - length[i] >= 0) {
// 			if (memo[n] == rodCutting(n - length[i], length, prices, m, memo) + prices[i]) {
// 				cout << length[i] << " " << prices[i] << '\n';
// 				trace_rod_cutting(n - length[i], length, prices, m, memo);
// 				return;
// 			}
// 		}
// 	}

// }

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	int length[m], prices[m];

	for (int i = 0; i < m; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> prices[i];
	}

	int memo[n + 1];
	memset(memo, -1, sizeof(memo));

	// cout << n << " " << m;

	pair<int, int> res = rodCutting(n, length, prices, m);

	cout << res.first << " " << res.second;

	// trace_rod_cutting(n, length, prices, m, memo, 0);









	return 0;
}