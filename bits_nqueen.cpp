#include<bits/stdc++.h>

using namespace std;

const int N = 15;
int grid[N][N], cnt;

bool is_safe(int row, int col) {
	// check vertically up
	int i = row, j = col;
	while (i >= 0) {
		if (grid[i][j]) return false;
		i--;
	}

	// check left diagonal up
	i = row, j = col;
	while (i >= 0 && j >= 0) {
		if (grid[i][j]) return false;
		i--; j--;
	}

	// check right diagonal up
	i = row, j = col;
	while (i >= 0 && j < N) {
		if (grid[i][j]) return false;
		i--; j++;
	}

	return true;
}

void nqueen(int row) {

	if (row == N) {
		cnt++;
		// for (int i = 0; i < N; i++) {
		// 	for (int j = 0; j < N; j++) {
		// 		cout << (grid[i][j] ? "Q " : ". ");
		// 	} cout << '\n';
		// }
		// cout << '\n';
		return;
	}

	for (int col = 0; col < N; col++) {
		if (is_safe(row, col)) {
			grid[row][col] = 1;
			nqueen(row + 1);
			// here
			// backtrack
			grid[row][col] = 0;
		}
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	nqueen(0);

	cout << cnt;

	return 0;
}