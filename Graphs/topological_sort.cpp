#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Topological Sort - https://cp-algorithms.com/graph/topological-sort.html
// -> Number the vertices in such a way that:
//    • Every edge is from a vertex with smaller no. to a larger no.
// -> Only exists for Directed Acyclic Graphs
// -> Multiple Topological Ordering can exist for one graph

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> vis(n);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
	}
	auto topo_dfs = [&] (vector<vector<int>> &adj_) -> vector<int> {
		vis.assign(n, 0);
		vector<int> order_;
		auto helper = [&] (const auto &self, int node) -> void {
			vis[node] = 1;
			for(auto &child: adj_[node])
				if(!vis[child])
					self(self, child);
			order_.push_back(node);
		};
		for(int i = 0; i < n; i++)
			if(!vis[i])
				helper(helper, i);
		reverse(order_.begin(), order_.end());
		return order_;
	};
	auto order = topo_dfs(adj);  
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}
