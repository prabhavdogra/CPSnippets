#include <bits/stdc++.h>
using namespace std;

class DSU {
	public:
	vector<int> parent, len;
	DSU(int n) {
		parent.resize(n);
		len.resize(n);
		for(int i = 0; i < n; i++) {
			parent[i] = i;
			len[i] = 1;
		}
	}
	int getParent(int u) {
		if(parent[u] == u)
			return u;
		return parent[u] = getParent(parent[u]); // Path Compression
	}
	void unionSets(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		if(a != b) {
			if(len[a] < len[b])
				swap(a, b);
			parent[b] = a;
			len[a] += len[b];
		}
	}
	int getSize(int x) { return len[x] = len[getParent(x)]; }
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	DSU dsu(n);
	
	return 0;
}
