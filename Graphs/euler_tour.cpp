#include <bits/stdc++.h>
using namespace std;
#define int long long int

class euler_tour {
public:
    int timer = 0;
    vector<vector<int>> adj;
    vector<int> start, end;
    euler_tour() {}
    euler_tour(vector<vector<int>> &a) {
        adj = a;
        start.assign(a.size(), 0);
        end.assign(a.size(), 0);
        dfs_precom(0, 0);
    }
    void dfs_precom(int node, int parent) {
        start[node] = timer;
        for(auto &child: adj[node]) {
            if(child == parent) continue;
            timer++;
            dfs_precom(child, node);
        }
        end[node] = timer;
        return;
    };
};

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
    vector<int> start(n), end(v);
    auto dfs = [&] (const auto &self, int node, int parent) -> void {
        start[node] = end[node] = timer;
        for(auto &child: adj[node]) {
            if(child == parent) continue;
            timer++;
            self(self, child, node);
            end[node] = timer;
        }
        return;
    };
    dfs(dfs, 0, 0);
    return 0;
}
