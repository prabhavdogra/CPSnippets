#include <bits/stdc++.h>
using namespace std;
#define int long long int

// O(n log log n)
template <int SZ = 1'000'000>
struct etf {
    vector<int> phi;
    etf() {
        phi.resize(SZ + 1);
        phi[0] = 0;
        phi[1] = 1;
        for (int i = 2 ; i <= SZ ; i++)
            phi[i] = i;
        for (int i = 2 ; i <= SZ ; i++)
            if(phi[i] == i)
                for (int j = i ; j <= SZ ; j += i)
                    phi[j] -= phi[j] / i;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    etf<1'000'000> t;
    // cal.phi[n];
    
    return 0;
}
