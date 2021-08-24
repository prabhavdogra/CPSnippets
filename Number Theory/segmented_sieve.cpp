#include <bits/stdc++.h>
using namespace std;
#define int long long int

// O(R - L + 1) log log R + sqrt(R) log log sqrt(R)
template <int64_t L, int64_t R>
struct segmentedSieve {
    vector<int64_t> primes, _primes;
    vector<bool> _isPrime, mark;
    segmentedSieve() {
    int64_t lim = sqrtl(R);
    _isPrime.assign(R - L + 1, true);
    mark.assign(lim + 1, false);
    for(int64_t i = 2; i <= lim; i++)
        if(!mark[i]) {
            _primes.emplace_back(i);
        for(int64_t j = i * i; j <= lim; j += i) mark[j] = true;
    }

    for(int64_t i: _primes)
    for(int64_t j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
    	_isPrime[j - L] = false;
    if(L == 1) _isPrime[0] = false;
    int num = L - 1;
    for(int64_t i: _isPrime)
        if(num++ && i) primes.push_back(num);
    }
    bool isPrime(int64_t num) {
        return _isPrime[num - L]; 
    }
};

segmentedSieve<1000'000'000, 1000'000'009> t;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    return 0;
}
