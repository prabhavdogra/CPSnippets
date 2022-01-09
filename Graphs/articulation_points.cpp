#include <bits/stdc++.h>
using namespace std;

class articulation_point {
public:
	vector<int> vis, dis, low, isCutpoint, cutpoints;
	articulation_point(const vector<vector<int>> &adj_) {
		int timer = 0, n = adj_.size();
		vis = dis = low = isCutpoint = vector<int>(n, 0);
		auto dfs = [&] (const auto &self, int node, int par = -1) -> void {
			vis[node] = 1;
			dis[node] = low[node] = timer++;
			int children = 0;
			for(auto child: adj_[node]) {
				if(child == par) continue;
				if(vis[child]) 
					low[node] = min(low[node], dis[child]);
				else {
					self(self, child, node);
					low[node] = min(low[node], low[child]);
					if(low[child] >= dis[node] && par != -1)
						isCutpoint[node] = 1;
					children++;
				}
			}
			if(par == -1 && children > 1)
				isCutpoint[node] = 1;
		};
		for(int i = 0; i < n; i++)
			if(!vis[i])
				dfs(dfs, i);
		for(int i = 0; i < n; i++)
			if(isCutpoint[i])
				cutpoints.push_back(i);
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	articulation_point t(adj);
	return 0;
}
