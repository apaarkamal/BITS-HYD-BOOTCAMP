#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector<int> gr[N];
int vis[N], dis[N];

void dfs(int cur) {
	cout << cur << '\n';
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x);
		}
	}
	// cout << cur << '\n';
	return;
}

void bfs(int root) {
	queue<int> Q;
	Q.push(root);
	dis[root] = 0;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		vis[cur] = 1;
		cout << cur << '\n';
		for (auto x : gr[cur]) {
			// weighted graph
			// int node = x.first;
			// int w = x.second
			// dis[node] = dis[cur] + w;
			if (!vis[x]) {
				dis[x] = dis[cur] + 1;
				Q.push(x);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// n represents vertices
	// m represents edges
	int n, m;
	cin >> n >> m;

	// m lines contains pair (a,b)
	// there is an edge berween (a,b)
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		gr[a].push_back(b);
		// undirected graph
		gr[b].push_back(a);
	}

	// O(V+E)
	// for (int i = 1; i <= n; i++) {
	// 	if (!vis[i]) dfs(i);
	// }

	// for (int i = 1; i <= n; i++) {
	// 	if (!vis[i]) bfs(i);
	// }

	bfs(5);

	for (int i = 1; i <= n; i++) {
		cout << i << " " << dis[i] << '\n';
	}


	return 0;
}