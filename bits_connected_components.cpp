#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int vis[N];

void dfs(int cur, int col) {
	vis[cur] = col;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x, col);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	int col = 1;

	// O(n)
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i, col), col++;
	}

	for (int i = 1; i <= n; i++) {
		cout << i << " " << vis[i] << '\n';
	}

	// O(n+q)
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << (vis[x] == vis[y] ? "same component" : "different component") << '\n';
	}












	return 0;
}