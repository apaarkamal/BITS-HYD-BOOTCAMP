#include<bits/stdc++.h>

using namespace std;

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

	int left[n], right[n];
	stack<int> St;

	// increasing stack of a[i]
	for (int i = n - 1; i >= 0; i--) {
		while (!St.empty() && a[St.top()] > a[i]) {
			int top_index = St.top();
			left[top_index] = i;
			St.pop();
		}
		St.push(i);
	}

	while (!St.empty()) {
		left[St.top()] = -1;
		St.pop();
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << left[i] << " ";
	// }

	// increasing stack of a[i]
	for (int i = 0; i < n; i++) {
		while (!St.empty() && a[St.top()] > a[i]) {
			int top_index = St.top();
			right[top_index] = i;
			St.pop();
		}
		St.push(i);
	}

	while (!St.empty()) {
		right[St.top()] = n;
		St.pop();
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << right[i] << " ";
	// }

	int mx = 0;

	for (int i = 0; i < n; i++) {
		int length = right[i] - left[i] - 1;
		int area = length * a[i];
		mx = max(mx, area);
	}

	cout << mx;






	return 0;
}