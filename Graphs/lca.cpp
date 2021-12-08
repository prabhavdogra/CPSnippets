#include <bits/stdc++.h>
using namespace std;

class LCA {
public:
	int n, ln;
	vector<int> level;
	vector<vector<int>> dp, adj;
	LCA(vector<vector<int>> &a) {
		n = a.size();
		adj = a;
		level.assign(n, 0);
		ln = ceil(log2(n));
		dp.assign(n, vector<int> (ln + 1));
		precom(0, 0);
	}
	void precom(int node, int parent) {
		level[node] = level[parent] + 1;
		dp[node][0] = parent;

		for(int i = 1; i < ln + 1; i++)
			dp[node][i] = dp[dp[node][i - 1]][i - 1];
		
		for(auto &child: adj[node])
			if(child != parent)
				precom(child, node);
		cout << '\n';
	}	
	int lca(int u, int v) {
		if(level[u] < level[v])
			swap(u, v);
		int dif = level[u] - level[v];
		for(int i = 0; i < ln + 1; i++)
			if((1<<i) & dif)
				u = dp[u][i];
		if(u == v)
			return u;
		for(int i = ln; i >= 0; i--)
			if(dp[u][i] != dp[v][i])
				u = dp[u][i], v = dp[v][i];
		return dp[u][0];
	}
};

// LCA t(adj);
// NOTE: Returns answer in 0-based indexing

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	return 0;
}
