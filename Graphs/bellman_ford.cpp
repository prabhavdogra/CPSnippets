#include <bits/stdc++.h>
using namespace std;
#define int long long int
constexpr int INF = 1e18;

struct edges {
	int u, v, cost;
};
struct bellman_ford {
	int negativeCyclePresent;
	vector<int> negativeCycle;
	bellman_ford() {}
	bellman_ford(int n, int m, int src, vector<edges> e) {
		vector<int> dis(n, INF);
		dis[src] = 0;
		vector<int> par(n);
		for(int i = 0; i < n; i++) {
			negativeCyclePresent = -1;
			for(auto [u, v, w]: e){
				if(dis[u] + w < dis[v]){
					dis[v] = dis[u] + w;
					par[v] = u;
					negativeCyclePresent = v;
				}
			}
		}
		if(negativeCyclePresent == -1)
			negativeCyclePresent = 0;
		else {
			for(int i = 0; i < n; i++)
				negativeCyclePresent = par[negativeCyclePresent];
			for(int x = negativeCyclePresent; ; x = par[x]){
				negativeCycle.push_back(x);
				if(x == negativeCyclePresent && negativeCycle.size() > 1) 
					break;
			}
			reverse(negativeCycle.begin(), negativeCycle.end());
			negativeCyclePresent = 1;
		}
	}
};

signed main() {
	int n, m;
	cin >> n >> m;
	vector<edges> e(m);
	for(int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].cost;
		e[i].u--; e[i].v--;
	}
	bellman_ford b(n, m, 0, e);
	if(b.negativeCyclePresent) {
		cout << "YES\n";
		for(auto x: b.negativeCycle)
			cout << x + 1 << " ";
		cout << "\n";
	}
	else
		cout << "NO\n";
}
