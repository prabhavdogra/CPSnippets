#include <bits/stdc++.h>
using namespace std;
#define int long long int
constexpr int INF = 1e18;

struct edges {
	int u, v, wt;
};

struct bellman_ford {
	int negativeCyclePresent = 0;
	vector<int> negativeCycle;
	bellman_ford() {};
	bellman_ford(vector<edges> &e, int n, int src) {
		int m = e.size();
		vector<int> dis(n, INF);
		dis[src] = 0;
		vector<int> path(n - 1);
		int lastRelaxed = -1;
		for(int i = 0; i < n; i++) {
			lastRelaxed = -1;
			for(auto [u, v, wt]: e) {
				if(dis[u] < INF && dis[v] > dis[u] + wt) {
					dis[v] = max(-INF, dis[u] + wt);
					path[v] = u;
					lastRelaxed = v;
				}
			}
		}
		if(lastRelaxed != -1) {
			negativeCyclePresent = 1;
			int y = lastRelaxed;
			for(int i = 0; i < n; i++)
				y = path[y];
			for(int cur = y; ; cur = path[cur]) {
				negativeCycle.push_back(cur);
				if(cur == y && negativeCycle.size() > 1)
					break;
			}
			reverse(negativeCycle.begin(), negativeCycle.end());
		}
		else
			negativeCyclePresent = 0;
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<edges> e(m);
	for(int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].wt;
		e[i].u--; e[i].v--;
	}
	bellman_ford b(e, n, 0);
	if(b.negativeCyclePresent) {
		cout << "YES\n";
		for(auto it: b.negativeCycle)
			cout << it + 1 << " ";
		cout << endl;
	}
	else cout << "NO\n";
	return 0;
}
