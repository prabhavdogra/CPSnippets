#include <bits/stdc++.h>
#define int long long int
using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, temp;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0), col(n, -1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    col[0] = 0;
    auto dfs = [&] (const auto& self, int v) -> bool {
        vis[v] = true;
        for (auto u : adj[v]) {
            if(col[u] == col[v]) 
                return false;
            if(!vis[u]) {
                col[u] = !col[v];
                if(!self(self, u)) 
                    return false;
            }
        }
        return true;
    };
    dfs(dfs, 0);
    return 0;
}
