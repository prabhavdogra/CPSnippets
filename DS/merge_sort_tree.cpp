#include <bits/stdc++.h>
using namespace std;
#define int long long int

template<typename NODE>
struct mergeTree {
    int size_;
    vector<vector<int>> t;
    mergeTree(vector<int> &a) {
        size_ = a.size();
        t.resize(4 * size_);
        build(a, 1, 1, size_);
    }
    int query(int l, int r, int k) {
        return queryHelper(1, 1, size_, l + 1, r + 1, k);
    }
    void merge(vector<int> &l, vector<int> &r, vector<int> &par) {
        int i = 0, j = 0;
        while (i < l.size() && j < r.size())
            if (l[i] <= r[j]) par.push_back(l[i]), i++;
            else par.push_back(r[j]), j++;
        while (i < l.size()) par.push_back(l[i]), i++;
        while (j < r.size()) par.push_back(r[j]), j++;
    }
    void build(vector<int> &a, int u, int l, int r) {
        if (l == r) {
            t[u].push_back(a[l - 1]);
            return;
        }
        int mid = (l + r) >> 1;
        build(a, 2 * u, l, mid);
        build(a, 2 * u + 1, mid + 1, r);
        merge(t[2 * u], t[2 * u + 1], t[u]);
    }
    int queryHelper(int u, int l, int r, int ql, int qr, int k) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return fun(t[u], k);
        int mid = (l + r) >> 1;
        int left = queryHelper(2 * u, l, mid, ql, qr, k);
        int right = queryHelper(2 * u + 1, mid + 1, r, ql, qr, k);
        return left + right;
    }
    int fun(vector<int> &a, int k) {
        return a.end() - upper_bound(a.begin(), a.end(), k);
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q, u, v;
    cin >> n >> q;
    vector<int> a(n), b(n);
    map<int, vector<int>> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    for(auto &[id, v]: m) {
        reverse(v.begin(), v.end());
        int last = 1e9;
        for(auto it: v) {
            b[it] = last;
            last = it;
        }
    }
    mergeTree<int> st(b);
    while(q--) {
        cin >> u >> v;
        cout << st.query(u - 1, v - 1, v - 1) << '\n';
    }
    return 0;
}
