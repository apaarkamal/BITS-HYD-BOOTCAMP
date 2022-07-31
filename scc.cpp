#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N], grr[N];
int vis[N];
vector<int> scc[N];
vector<int> topo_order;

void topo(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) topo(x);
	}
	topo_order.push_back(cur);
}

void dfs_reverse(int cur, int col) {
	vis[cur] = col;
	scc[col].push_back(cur);
	for (auto x : grr[cur]) {
		if (!vis[x]) {
			dfs_reverse(x, col);
		}
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
		grr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) topo(i);
	}
	reverse(topo_order.begin(), topo_order.end());

	// for (auto x : topo_order) cout << x << '\n';

	memset(vis, 0, sizeof(vis));

	int col = 1;
	for (auto i : topo_order) {
		if (!vis[i]) dfs_reverse(i, col), col++;
	}

	for (int i = 1; i < col; i++) {
		for (auto x : scc[i]) cout << x << " ";
		cout << '\n';
	}



	return 0;
}