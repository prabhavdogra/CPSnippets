#include <bits/stdc++.h>
using namespace std;
namespace atcoder {

template <class NODE,
          NODE (*operation)(NODE, NODE),
          NODE (*initialization)(),
          class UPDATE,
          NODE (*apply)(UPDATE, NODE),
          UPDATE (*combine)(UPDATE, UPDATE),
          UPDATE (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    explicit lazy_segtree(int n) : lazy_segtree(vector<NODE>(n, initialization())) {}
    explicit lazy_segtree(const vector<NODE>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector<NODE>(2 * size, initialization());
        lz = vector<UPDATE>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, NODE x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    NODE query(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    NODE query(int l, int r) {
        r++;
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return initialization();
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        NODE sml = initialization(), smr = initialization();
        while (l < r) {
            if (l & 1) sml = operation(sml, d[l++]);
            if (r & 1) smr = operation(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return operation(sml, smr);
    }

    NODE all_query() { return d[1]; }

    void rupd(int p, UPDATE f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = apply(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void rupd(int l, int r, UPDATE f) {
        r++;
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(NODE)> int descent_right(int l) {
        return descent_right(l, [](NODE x) { return g(x); });
    }
    template <class G> int descent_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(initialization()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        NODE sm = initialization();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(operation(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(operation(sm, d[l]))) {
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

    template <bool (*g)(NODE)> int descent_left(int r) {
        return descent_left(r, [](NODE x) { return g(x); }) - 1;
    }
    template <class G> int descent_left(int r, G g) {
        r++;
        assert(0 <= r && r <= _n);
        assert(g(initialization()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        NODE sm = initialization();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(operation(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(operation(d[r], sm))) {
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
    vector<NODE> d;
    vector<UPDATE> lz;

    void update(int k) { d[k] = operation(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, UPDATE f) {
        d[k] = apply(f, d[k]);
        if (k < size) lz[k] = combine(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

} using namespace atcoder;
#define int long long int

// Range Min Query + Range Assignment Update
// More Examples:
// https://betrue12.hateblo.jp/entry/2020/09/23/005940

using NODE = int;
using UPDATE = int;

NODE initialization() { return NODE(1e18); }
NODE operation(NODE l, NODE r) {
    return min(l, r);
}
NODE apply(UPDATE l, NODE r) {
    return (l != -1 ? l : r);
}
int target;
bool f(NODE u) {
    return 1;
}
UPDATE id() { return -1; }
UPDATE combine(UPDATE cur, UPDATE prev) { return (cur != -1 ? cur : prev) ; }

// -> Change target
// st.descent_right<g>(left_index)
//   -> returns n, if not found
// st.descent_left<g>(right_index)
//   -> returns -1, if not found

// vector<NODE> a;
// segtree<NODE, operation, initialize> st(a);
// st.query(start, end);
// st.upd(index, value);

signed main() {   
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n, 0);
	lazy_segtree<NODE, operation, initialization, UPDATE, apply, combine, id> st(a);
    while(q--) {
        int type, l, r, v;
        cin >> type >> l >> r;
        if(type == 1) {
            cin >> v;
            st.rupd(l, r - 1, v);
        }
        else {
            cout << st.query(l , r - 1) << '\n';
        }
    }
	return 0;
}
