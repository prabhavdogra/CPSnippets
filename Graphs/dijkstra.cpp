#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> dis;
 
void dijkstra(int src) {
    dis.resize(n, 1e18);
    priority_queue<pair<int, int>> q;
    q.push({0, src});
    dis[src] = 0;
    while(q.size()) {
        int node = q.top().second;
        int dis_n = q.top().first;
        q.pop();
        if(-dis_n != dis[node]) 
            continue;
        for(auto it: adj[node]) {
            if(dis[it.first] > dis[node] + it.second) {
                dis[it.first] = dis[node] + it.second;
                q.push({-dis[it.first], it.first});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.clear(); adj.resize(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
    }
    dijkstra(0);
    for(auto it: dis)
        cout << it << " ";
    cout << '\n';
}

signed main() {   
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
