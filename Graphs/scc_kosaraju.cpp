#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(n), radj(n);
	vector<int> vis(n);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		radj[v - 1].push_back(u - 1);
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
	auto scc_kosaraju = [&] (vector<int> order_) -> vector<vector<int>> {
		vector<vector<int>> components_;
		vis.assign(n, 0);
		auto helper = [&] (const auto &self, int node) -> void {
			vis[node] = 1;
			components_.back().push_back(node);
			for(auto child: radj[node])
				if(!vis[child])
					self(self, child);
		};
		for(auto node: order) {
			if(!vis[node]) {
				components_.push_back(vector<int>());
				helper(helper, node);
			}
		}
		return components_;
	};
	auto components = scc_kosaraju(order);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}
