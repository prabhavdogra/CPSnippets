#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long int

// Ordered set
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered multiset
// template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ordered_set <pair<int, int>> t;
// ordered_set <int> x;

//  .insert(val)
//  .erase(iter/val)
//  .order_of_key(k) -> Number of items strictly smaller than k
//  .find_by_order(k) -> K-th element in a set (counting from zero)

// https://cses.fi/problemset/task/1144/

signed main() {   
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    ordered_set <pair<int, int>> t;
    vector<int> p(n);
    for(int i = 0 ; i < n ; i++)
        cin >> p[i], t.insert({p[i], i});
    while(q--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == '!') {
            t.erase({p[a - 1], a - 1});
            p[a - 1] = b;
            t.insert({p[a - 1], a - 1});
        }
        else {
            cout << t.order_of_key({b, 1e10}) - t.order_of_key({a - 1, 1e10}) << endl;
        }
    }
    return 0;
}
