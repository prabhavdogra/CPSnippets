#include <bits/stdc++.h>
using namespace std;
#define int long long int

constexpr int64_t INF = 1e17;

// O(V^3)
vector<vector<int>> floydWarshall(vector<vector<int>> &adj_) {
	int n = adj_.size();
	auto res = adj_;
	for(int i = 0; i < n; i++) // Self-Loop
		res[i][i] = 0;
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
	return res;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, u, v, wt;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int> (n, INF));
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
		adj[u - 1][v - 1] = wt;
		// adj[v - 1][u - 1] = wt;
	}
	auto dis = floydWarshall(adj);
	
	return 0;
}
