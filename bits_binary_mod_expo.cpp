#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int m = 5;

// a,b < 1e9+7
int add(int a, int b) {return (a + b) % m;}
int sub(int a, int b) {return ((a - b) % m + m) % m;}
int mul(int a, int b) {return (a * b) % m;}

int mod_power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

int inv(int a) {
	return mod_power(a, m - 2);
}

int divide(int a, int b) {return mul(a, inv(b));}

int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;
	cin >> a >> b;
	// cout << power(a, b);

	cout << divide(35, 7);

	return 0;
}