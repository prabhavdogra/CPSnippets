#include <bits/stdc++.h>
using namespace std;
#define int long long int

class DSU {
	public:
	vector<int> parent, len;
	DSU(int n) {
		parent.resize(n);
		len.resize(n);
		for(int i = 0; i < n; i++) {
			parent[i] = i;
			len[i] = 1;
		}
	}
	int getParent(int u) {
		if(parent[u] == u)
			return u;
		return parent[u] = getParent(parent[u]); // Path Compression
	}
	void unionSets(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		if(a != b) {
			if(len[a] < len[b])
				swap(a, b);
			parent[b] = a;
			len[a] += len[b];
		}
	}
	int getSize(int x) { return len[x] = len[getParent(x)]; }
};

struct Edge {
	int u, v, wt;
	bool operator<(Edge const& other) {
		return wt < other.wt;
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, u, v, wt;
	cin >> n >> m;
	vector<Edge> adj;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
		// Undirected
		adj.push_back({u - 1, v - 1, wt});
		adj.push_back({v - 1, u - 1, wt});
	}
	// O(M log(N))
	auto kruskal = [&] (vector<Edge> &adj_) -> pair<vector<Edge>, int> {
		int cost_ = 0, n_ = adj_.size();
		DSU t_(n);
		vector<Edge> mstEdges_;
		sort(adj_.begin(), adj_.end());
		for(auto &[u_, v_, wt_]: adj_) {
			if(t_.getParent(u_) != t_.getParent(v_)) {
				cost_ += wt_;
				t_.unionSets(u_, v_);
				mstEdges_.push_back({u_, v_, wt_});
			}
		}
		if(t_.getSize(0) == n) 
			return {mstEdges_, cost_};
		return {vector<Edge> (), -1};
	};
	auto [mstEdges, mstCost] = kruskal(adj);
  
	return 0;
}
