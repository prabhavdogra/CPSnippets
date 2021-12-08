#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
void dfs(int node, int parent) {
    for(auto &child: adj[node])
        if(child != parent)
            dfs(child, node);
    return;
}

void dfs_tree_rec() {
    int n, u, v;
    cin >> n;
    adj.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    dfs(0, 0);
}

void dfs_tree_lamda() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    auto dfs = [&] (const auto &self, int node, int parent) -> void {
        for(auto &child: adj[node])
            if(child != parent)
                self(self, child, node);
        return;
    };
    dfs(dfs, 0, 0);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	dfs_tree_lamda();
    	dfs_tree_rec();
	
	return 0;
}
