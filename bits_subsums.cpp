#include<bits/stdc++.h>
#define int long long int

using namespace std;

// O(m*2^m)
vector<int> giveSubsetSums(vector<int> a) {
	int m = a.size();
	vector<int> res;
	for (int i = 0; i < (1 << m); i++) {
		int sum = 0;
		for (int bit = 0; bit < m; bit++) {
			if ((i >> bit) & 1) {
				sum += a[bit];
			}
		}
		res.push_back(sum);
	}
	return res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, A, B;
	cin >> n >> A >> B;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> left, right;
	for (int i = 0; i < n / 2; i++) {
		left.push_back(a[i]);
	}
	for (int i = n / 2; i < n; i++) {
		right.push_back(a[i]);
	}

	// O(n/2*2^(n/2))
	vector<int> left_sum = giveSubsetSums(left);
	// O(n/2*2^(n/2))
	vector<int> right_sum = giveSubsetSums(right);

	// m = lenght of array = total subsets = 2^n/2
	// O(mlog(m))
	sort(right_sum.begin(), right_sum.end());

	// for (auto x : left_sum) cout << x << " "; cout << '\n';
	// for (auto x : right_sum) cout << x << " "; cout << '\n';


	int ans = 0;

	for (auto x : left_sum) {
		// A<= x+y <=B
		// A-x <= y <= B-x
		ans += (upper_bound(right_sum.begin(), right_sum.end(), B - x)
		        - lower_bound(right_sum.begin(), right_sum.end(), A - x));

		// cout << x << " " << A - x << " " << B - x << '\n';
	}

	cout << ans;






	return 0;
}