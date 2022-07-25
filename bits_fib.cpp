#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int sz = 2, mod = 1e9 + 7;

struct Matrix {
	int mat[sz][sz];
	Matrix () {
		memset(mat, 0, sizeof(mat));
	}
	void identity() {
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < sz; i++) {
			mat[i][i] = 1;
		}
	}
	void print() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				cout << mat[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
	// O(sz^3)
	Matrix operator* (const Matrix &a) const {
		Matrix res;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				// cell i and j
				// ith row * jth column
				for (int k = 0; k < sz; k++) {
					res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
				}
			}
		}
		return res;
	}
};

// O((sz^3)*(log(n)))
int fib(int n) {
	if (n == 0) return 0;
	if (n <= 2) return 1;

	Matrix res;
	res.identity();

	Matrix t;
	t.mat[0][0] = t.mat[0][1] = t.mat[1][0] = 1;
	t.mat[1][1] = 0;

	n--;
	while (n) {
		if (n & 1) res = res * t;
		t = t * t;
		n /= 2;
	}

	return res.mat[0][0];
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	// O(log(n))
	cout << fib(60);


	return 0;
}