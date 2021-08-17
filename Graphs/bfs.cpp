#include <bits/stdc++.h>
#define int long long int
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> path;
 
void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(q.size()) {
        auto x = q.front();
        q.pop();
        for(auto it: adj[x]) {
            if(!vis[it]) {
                // Reduce Queue as much as possible
                q.push(it);
                vis[it] = 1;
                path[it] = x;
            }
        }
    }
}

void bfs_rec() {
    adj.clear();
    int u, v;
    cin >> n >> m;
    adj.resize(n);
    path.assign(n, -1);
    vis.assign(n, 0);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
}

void bfs_lamda() {
    int u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0), path(n, -1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&] (int src) -> void {
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while(q.size()) {
            auto x = q.front();
            q.pop();
            for(auto it: adj[x]) {
                if(!vis[it]) {
                    // Reduce Queue as much as possible
                    q.push(it);
                    vis[it] = 1;
                    path[it] = x;
                }
            }
        }
    };
    bfs(0);
}

int main() {   
    ios::sync_with_stdio(0); cin.tie(0);
    
    bfs_rec();
    bfs_lamda();

    return 0;
}