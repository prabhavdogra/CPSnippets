#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long int

// For Leetcode/Interviewbit
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered set
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered multiset
// template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Special Case: Erasing in ordered multiset
// os.erase(os.find_by_order(os.order_of_key(val)));

// ordered_set <pair<int, int>> t;
// ordered_set <int> x;

//  .insert(val)
//  .erase(iter/val)
//  .order_of_key(k) -> Number of items strictly smaller than k
//  .find_by_order(k) -> K-th element in a set (counting from zero)

signed main() {   
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ordered_set <pair<int, int>> t;
    
    return 0;
}
