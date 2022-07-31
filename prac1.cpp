#include<bits/stdc++.h>

using namespace std;

void tower_of_hanoi(int n, char source, char helper, char destination) {
	if (n == 0) return;

	tower_of_hanoi(n - 1, source, destination, helper);
	cout << source << " --> " << destination << '\n';
	tower_of_hanoi(n - 1, helper, source, destination);

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	tower_of_hanoi(n, 'A', 'B', 'C');



	return 0;
}