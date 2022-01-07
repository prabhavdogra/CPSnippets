#include <bits/stdc++.h>
using namespace std;
#define int long long int
constexpr int INF = 1e18;

struct Edge {
    int first = INF, second = -1;
    bool operator<(Edge const& other) const {
        return make_pair(first, second) < make_pair(other.first, other.second);
    }
};

int n;
vector<vector<Edge>> adj;

void prim() {
    int ans = 0;
    vector<Edge> mstEdges(n);
    mstEdges[0].first = 0;
    set<Edge> q;
    q.insert({0, 0});
    vector<int> vis(n);
    for(int i = 0; i < n; ++i) {
        if(q.empty()) // No MST case
            return cout << "IMPOSSIBLE\n", void();
        int v = (*q.begin()).second;
        vis[v] = 1;
        ans += (*q.begin()).first;
        q.erase(q.begin());
        if(mstEdges[v].second != -1) {
            // To print the MST edges
            // cout << v << " " << mstEdges[v].second << '\n';
        }
        for(auto &[wt, node] : adj[v]) {
            if(!vis[node] && wt < mstEdges[node].first) {
                q.erase({mstEdges[node].first, node});
                mstEdges[node] = {wt, v};
                q.insert({wt, node});
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m, u, v, wt;
	cin >> n >> m;
	adj.resize(n);
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
        // Undirected
		adj[u - 1].push_back({wt, v - 1});
		adj[v - 1].push_back({wt, u - 1});
	}
	prim();
	return 0;
}
