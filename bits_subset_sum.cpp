#include<bits/stdc++.h>

using namespace std;

// O(2^n) without memoisation

map<int, int> memo[100];

bool findSubsetSum(int index, int *a, int sum, int n) {
	if (index == n) {
		return (sum == 0);
	}

	if (memo[index][sum] != -1) return memo[index][sum];

	// for index i
	// exclude
	bool ans = findSubsetSum(index + 1, a, sum, n);
	// include
	if (sum - a[index] >= 0) {
		ans |= findSubsetSum(index + 1, a, sum - a[index], n);
	}
	return memo[index][sum] = ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum;
	cin >> sum;


	cout << findSubsetSum(0, a, sum, n);


	return 0;
}