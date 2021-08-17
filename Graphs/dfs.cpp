#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int v) {
    vis[v] = true;
    for (auto u : adj[v]) {
        if(!vis[u]) {
            dfs(u);
        }
    }
    return;
}

void dfs_rec() {
    adj.clear();
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    vis.assign(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
}


void dfs_lamda() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);
    // for(int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    auto dfs = [&] (const auto& self, int v) -> void {
        vis[v] = true;
        for (auto u : adj[v]) {
            if(!vis[u]) {
                self(self, u);
            }
        }
        return;
    };

    dfs(dfs, 0);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    dfs_lamda();
    dfs_rec();
    
    return 0;
}
