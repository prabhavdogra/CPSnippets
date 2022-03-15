#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Min distance Dijkstra's
struct dijkstra {
	vector<int64_t> dis;
	dijkstra() {}
	dijkstra(vector<vector<pair<int64_t, int64_t>>> &adj, int64_t src) {
		dis.assign(adj.size(), (int64_t)1e18);
		priority_queue<pair<int, int>> q;
		q.push({0, src});
		dis[src] = 0;
		while(q.size()) {
			auto [dis_n, prev] = q.top();
			q.pop();
			// q -> {-distance, prev}
			if(-dis_n != dis[prev])
				continue;
			for(auto [cur, wt]: adj[prev]) {
				if(dis[cur] > dis[prev] + wt) {
					dis[cur] = dis[prev] + wt;
					q.push({-dis[cur], cur});
				}
			}
		}
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int64_t, int64_t>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u - 1].push_back({v - 1, wt});
    }
    auto d1 = dijkstra(adj, 0);
    for(auto it: d1.dis)
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
