#include<bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	cout << gcd(0, 42);

	return 0;
}