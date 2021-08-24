#include <bits/stdc++.h>
using namespace std;
#define int long long int

// O(n log n)
template <int SZ = 1'000'000>
struct n_divisors {
    vector<vector<int>> div;
    n_divisors() {
        div.resize(SZ + 1);
        for(int i = 2; i <= SZ; i++) {
            int j = i;
            while(j <= SZ)
                div[j].push_back(i), j += i;
	}
    }
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	n_divisors<100'000> t;
	
	return 0;
}
