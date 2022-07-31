#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int vis[N];

vector<int> topological_order;

void topo(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) topo(x);
	}
	topological_order.push_back(cur);
	return;
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
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) topo(i);
	}

	reverse(topological_order.begin(), topological_order.end());

	for (auto x : topological_order) cout << x << " ";


	return 0;
}