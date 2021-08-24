#include <bits/stdc++.h>
using namespace std;
constexpr int64_t M = 1e9 + 7;
#define int long long int

class pnc {
public:
    int mod_;
    vector<int> fac, inv;
    int modpow(int x, int n, int m) {
        if(!x) return 0;
        int res = 1;
        x = x % m;
        while(n) {
            if(n&1)
                res = (res * x) % m;
            n = (n >> 1);
            x = (x * x) % m;
        }
        return res;
    }
    pnc(int n, int mod) {
        this->mod_ = mod;
        fac.assign(n + 1, 0);
        inv.assign(n + 1, 0);
        fac[0] = 1;
        for(int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % mod;
        inv[n] = modpow(fac[n], mod - 2, mod);
        for(int i = n - 1 ; i >= 0; i--)
            inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
    int ncr(int n, int r) {
        if(n < r || n < 0 || r < 0) return 0;
        return fac[n] * inv[r] % mod_ * inv[n - r] % mod_;
    }
    int npr(int n, int r) {
        return ncr(n, r) * fac[r] % mod_;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    pnc cal(3e5, M);
    // cal.ncr(n, r)
    // cal.npr(n, r)
    
    return 0;
}
