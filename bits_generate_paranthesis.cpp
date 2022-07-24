#include<bits/stdc++.h>

using namespace std;

void generate_paranthesis(int index, string res, int open, int close, int n, int &num) {

	if (index == n) {
		cout << res << '\n';
		num++;
		return;
	}

	// add '('
	if (open < n / 2) {
		generate_paranthesis(index + 1, res + "(", open + 1, close, n, num);
	}

	// add '('
	if (close < n / 2 && close < open) {
		generate_paranthesis(index + 1, res + ")", open, close + 1, n, num);
	}

}

// 2, 5, 14

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 6;
	int num = 0;
	generate_paranthesis(0, "", 0, 0, n, num);
	cout << num << '\n';

	return 0;
}