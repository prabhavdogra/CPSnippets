#include <bits/stdc++.h>
using namespace std;
constexpr int64_t M = 1e9 + 7;
#define int long long int

class pnc {
public:
    int mod_;
    vector<int> fac, finv;
    int inv(int n, int mod) {
        return modpow(n, mod - 2, mod);
    }
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
        finv.assign(n + 1, 0);
        fac[0] = 1;
        for(int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % mod;
        finv[n] = inv(fac[n], mod);
        for(int i = n - 1 ; i >= 0; i--)
            finv[i] = (finv[i + 1] * (i + 1)) % mod;
    }
    int ncr(int n, int r) {
        if(n < r || n < 0 || r < 0) return 0;
        return fac[n] * finv[r] % mod_ * finv[n - r] % mod_;
    }
    int npr(int n, int r) {
        return ncr(n, r) * fac[r] % mod_;
    }
};

pnc t(3e5, M);
// t.ncr(n, r)
// t.npr(n, r)

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    return 0;
}
