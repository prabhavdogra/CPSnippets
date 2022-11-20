#include <bits/stdc++.h>
using namespace std;
#define int long long int

template<typename NODE>
class sparse_table {
public:
	vector<vector<NODE>> sp;
	vector<int> logarithm, a;
	int n, maxLog;
	sparse_table(vector<int> &arr) {
		n = arr.size();
		a = arr;
		sp.resize(n);
		logarithm.resize(n + 1);
		maxLog = log2(n);
		logarithm[1] = 0;
		for(int i = 2; i <= n; i++) {
			logarithm[i] = logarithm[i / 2] + 1;
		}
		for(int i = 0; i < n; i++) {
			sp[i].resize(maxLog + 1);
			fill(sp[i].begin(), sp[i].end(), NODE());
		}
		build();
	}
	void build() {
		for(int i = 0; i < n; i++)
			sp[i][0] = NODE(a[i]);
		for(int i = 1; i <= maxLog; i++) {
			for(int j = 0; (j + (1 << i)) <= n; j++)
				sp[j][i].merge(sp[j][i - 1], sp[j + (1 << (i - 1))][i - 1]);
		}
	}
	NODE queryNormal(int left, int right) {
		NODE ans = NODE();
		for(int j = logarithm[right - left + 1]; j >= 0; j--) {
			if((1 << j) <= right - left + 1) {
				ans.merge(ans, sp[left][j]);
				left += (1 << j);
			}
		}
		return ans;
	}
	NODE queryIdempotent(int left, int right) {
		int j = logarithm[right - left + 1];
		NODE ans = NODE();
		ans.merge(sp[left][j], sp[right - (1 << j) + 1][j]);
		return ans;
	}
};

struct NODE1 {
	int v;
	NODE1() { v = 0; }
	NODE1(int val) { v = val; }
	void merge(NODE1 &l, NODE1 &r) { v = max(l.v, r.v); }
};

signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &it: a)
		cin >> it;
	sparse_table<NODE1> sp(a);
	cout << sp.queryIdempotent(0, n - 1).v << " ";
	
	return 0;
}
