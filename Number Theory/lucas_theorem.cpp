#include <bits/stdc++.h>
using namespace std;
constexpr int64_t M = 1e9 + 7;
#define int long long int

// O(p^2 logp(n))
int modncrdp(int n, int r, int p) {
    int c[r + 1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = min(i, r); j > 0; j--) {
            c[j] = (c[j] + c[j-1]) % p;
        }
    }
    return c[r];
}

int modncr(int n, int r, int p) { // p should be prime
   if(r == 0) 
      return 1;
   int ni = n % p, ri = r % p;
   return (modncr(n/p, r/p, p) * modncrdp(ni, ri, p)) % p;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // modncr(n, r, M);

    return 0;
}
