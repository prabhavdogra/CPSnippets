#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Reversing the direction of all the edges gives us the transpose of the graph
// Kosaraju's Algorithms works on the principle that:
// Transposing the graph has no effect on SCC's

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
	}
	auto topo_dfs = [&] (vector<vector<int>> &adj_) -> vector<int> {
		vector<int> vis(adj_.size());
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
	auto scc = [&] (vector<vector<int>> adj_, vector<int> order_) -> vector<vector<int>> {
		vector<vector<int>> radj_(adj_.size());
		for(int i = 0; i < adj_.size(); i++)
			for(auto j: adj[i])
				radj_[j].push_back(i);
		vector<vector<int>> components_;
		auto vis = vector<int>(n, 0);
		auto helper = [&] (const auto &self, int node) -> void {
			vis[node] = 1;
			components_.back().push_back(node);
			for(auto child: radj_[node])
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
	auto components = scc(adj, order);
	auto condense = [&] (vector<vector<int>> adj_, vector<vector<int>> &components_) -> vector<vector<int>> {
		vector<int> color_(adj_.size());
		vector<vector<int>> adj_scc_(adj_.size());
		for(auto &component_: components_) {
			int col_ = component_[0];
			for(auto it: component_) {
				color_[it] = col_;
			}
		}
		for(int i = 0; i < n; i++) {
			for(auto j: adj_[i]) {
				if(color_[i] != color_[j])
					adj_scc_[color_[i]].push_back(color_[j]);
			}
		}
		return adj_scc_;
	};
	// components[i][0] -> Topologic Ordering for the Condensed Graph
	auto adj_scc = condense(adj, components);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}
