#include <bits/stdc++.h>
using namespace std;
#ifdef prabhav_
	#include "Headers/debug.cpp"
#endif

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
	}
	auto cycleChk = [&] (vector<vector<int>> adj_) -> vector<int> {
		int n_ = adj_.size();
		int cycle_start_ = -1, cycle_end_ = -1;
		vector<int> col_(n_), par_(n), cycle_;
		auto dfs = [&] (const auto &self, int node) -> bool {
		    col_[node] = 1;
			for(auto child : adj[node]) {
				if(col_[child] == 0) {
					par_[child] = node;
					if(self(self, child))
						return true;
				}
				else if(col_[child] == 1)
					return cycle_end_ = node, cycle_start_ = child, true;
			}
			col_[node] = 2;
			return false;
		};
	    for(int i = 0; i < n; i++)
    	    if(col_[i] == 0 && dfs(dfs, i))
            	break;
		if(cycle_start_ != -1) {
			cycle_.push_back(cycle_start_);
			for (int i = cycle_end_; i != cycle_start_; i = par_[i])
				cycle_.push_back(i);
			cycle_.push_back(cycle_start_);
			reverse(cycle_.begin(), cycle_.end());
		}
		return cycle_;
	};
	auto cycle = cycleChk(adj);
	
	return 0;
}
