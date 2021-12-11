#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, u, v;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int timer = 0;
    vector<int> a(n), start(n), end(v);
    auto dfs = [&] (const auto &self, int node, int parent) -> void {
        start[node] = end[node] = timer;
        a[timer] = node;
        for(auto &child: adj[node]) {
            if(child != parent) continue;
            timer++;
            self(self, child, node);
            end[node] = timer;
        }
        return;
    };
    dfs(dfs, 0, 0);
    return 0;
}