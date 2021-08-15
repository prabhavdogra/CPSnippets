#include<bits/stdc++.h>
using namespace std;
namespace atcoder {

template <class S, S (*operation)(S, S), S (*initialize)()> struct segtree {
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

    S get(int p) {
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

    S all_prod() { return d[1]; }

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
        return descent_left(r, [](S x) { return f(x); });
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

struct node{ int v; };
node initialize() { 
    return (node){-1}; 
}
node operation(node l, node r) { 
    node res;
    res.v = max(l.v, r.v);
    return res; 
}
int target;
bool f(node u) { 
    return u.v < target; 
}

signed main() {
    int n, q;
    cin >> n >> q;
    vector<node> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].v;
    segtree<node, operation, initialize> st(a);
    while(q--) {
        int type, i, j, v, x;
        cin >> type;
        if(type == 1) {
            cin >> i >> v;
            st.upd(i, (node){v});
        }
        else {
            cin >> target >> j;
            int id = st.descent_right<f>(j);
            if(id != n) cout << id << '\n';
            else cout << "-1\n";
        }
    }
}