#include <bits/stdc++.h>
using namespace std;
namespace atcoder {

template <class S, S (*operation)(const S&, const S&), S (*initialize)()> struct segtree {
public:
	segtree() : segtree(0) {}
	segtree(int n) : segtree(vector<S>(n, initialize())) {}
	int ceil_pow2(int n) {
		int x = 0;
		while ((1U << x) < (unsigned int)(n)) x++;
		return x;
	}

	segtree(const vector<S>& v) : _n(int(v.size())) {
		log = ceil_pow2(_n);
		size = 1 << log;
		d = vector<S>(2 * size, initialize());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void upd(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S query(int p) {
		assert(0 <= p && p < _n);
		return d[p + size];
	}

	S query(int l, int r) {
		r++;
		assert(0 <= l && l <= r && r <= _n);
		S sml = initialize(), smr = initialize();
		l += size;
		r += size;

		while (l < r) {
			if (l & 1) sml = operation(sml, d[l++]);
			if (r & 1) smr = operation(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return operation(sml, smr);
	}

	S all_query() { return d[1]; }

	template <bool (*f)(S)> int descent_right(int l) {
		return descent_right(l, [](S x) { return f(x); });
	}
	template <class F> int descent_right(int l, F f) {
		assert(0 <= l && l <= _n);
		assert(f(initialize()));
		if (l == _n) return _n;
		l += size;
		S sm = initialize();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!f(operation(sm, d[l]))) {
				while (l < size) {
					l = (2 * l);
					if (f(operation(sm, d[l]))) {
						sm = operation(sm, d[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = operation(sm, d[l]);
			l++;
		} while ((l & -l) != l);
		return _n;
	}

	template <bool (*f)(S)> int descent_left(int r) {
		r++;
		return descent_left(r, [](S x) { return f(x); }) - 1;
	}
	template <class F> int descent_left(int r, F f) {
		assert(0 <= r && r <= _n);
		assert(f(initialize()));
		if (r == 0) return 0;
		r += size;
		S sm = initialize();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!f(operation(d[r], sm))) {
				while (r < size) {
					r = (2 * r + 1);
					if (f(operation(d[r], sm))) {
						sm = operation(d[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = operation(d[r], sm);
		} while ((r & -r) != r);
		return 0;
	}

private:
	int _n, size, log;
	vector<S> d;
	void update(int k) { d[k] = operation(d[2 * k], d[2 * k + 1]); }
};

}
using namespace atcoder;
#define int long long int
constexpr int64_t INF = 2e18;

// Identity element: {0, addition}, {INF, min}, {-INF for max}
#define ID {-INF};

using S = int;
// struct S { int v; };
S initialize() { 
	return ID;
}
S operation(const S &l, const S &r) { 
	S res;
	res = max(l, r);
	return res;
}
int target;
bool f(S u) {
	return !(u >= target);
}

class hld {
public:
	int n;
	vector<S> wt;
	vector<vector<int>> adj;
	vector<int> sz, dep, top, heavyChild, pos, par;
	segtree<S, operation, initialize> st;
	hld() {}
	hld(vector<vector<int>> &adj_, vector<S> wt_) {
		adj = adj_;
		wt = wt_;
		n = adj_.size();
		st = segtree<S, operation, initialize> (n);
		sz = dep = pos = par = top = vector<int> (n);
		heavyChild = vector<int> (n, -1);
		precom();
	}
	void precom() {
		auto precom_ = [&] (const auto &self, int node, int parent) -> void {
			sz[node] = 1;
			int mxSz = 0;
			for(auto child: adj[node]) {
				if(child == parent) continue;
				par[child] = node;
				dep[child] = dep[node] + 1;
				self(self, child, node);
				sz[node] += sz[child];
				if(sz[child] > mxSz) {
					mxSz = sz[child];
					heavyChild[node] = child;
				}
			}	
		};
		precom_(precom_, 0, -1);
		int timer = 0;
		auto decomp_ = [&] (const auto &self, int node, int ptop) -> void {
			top[node] = ptop, pos[node] = timer++;
			st.upd(pos[node], wt[node]);
			if(heavyChild[node] != -1)
				self(self, heavyChild[node], ptop);
			for(auto child: adj[node])
				if(child != par[node] && child != heavyChild[node])
					self(self, child, child);
		};
		decomp_(decomp_, 0, 0);
	}
	S query(int a, int b) {
		S res = ID;
		while(top[a] != top[b]){
			if(dep[top[a]] < dep[top[b]])
				swap(a, b);
			res = operation(res, st.query(pos[top[a]], pos[a]));
			a = par[top[a]];
		}
		if(dep[a] > dep[b]) swap(a, b);
		return res = operation(res, st.query(pos[a], pos[b]));
	}
	void update(int a, S b) {
		st.upd(pos[a], b);
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, q, u, v;
	cin >> n >> m;
	vector<S> wt(n);
	for(auto &it: wt)
		cin >> it;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	hld t(adj, wt);
	cin >> q;
	while(q--) {

	}
	return 0;
}
