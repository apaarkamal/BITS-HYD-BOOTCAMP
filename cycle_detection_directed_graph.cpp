#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector<int> gr[N];
int vis[N];
bool cycle;

void dfs(int cur, int par) {
	vis[cur] = 1;

	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x, cur);
		}
		else if (x != par && vis[x] == 1) {
			// x was in the stack
			// x was an ancestor of cur
			cycle = true;
		}
	}

	vis[cur] = 2;
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// n represents vertices
	// m represents edges
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		gr[a].push_back(b);
	}

	// 0 as parent of 1
	dfs(1, 0);
	cout << cycle << '\n';

	return 0;
}