#include <bits/stdc++.h>
using namespace std;
#define int long long int

// O(n log log n)
template <int SZ = 1'000'000>
struct sieve {
    vector<bool> isPrime;
    vector<int> primes, spf;
    sieve() {
        spf.resize(SZ + 1);
        isPrime.assign(SZ + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i <= SZ; i++) {
            if(isPrime[i])
                primes.push_back(i), spf[i] = i;
            for(int j = 0; j < primes.size() && i * primes[j] <= SZ && primes[j] <= spf[i]; j++) {
                isPrime[i * primes[j]] = false;
                spf[i * primes[j]] = primes[j];
            }
        }
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    sieve<1'000'000> p;
	
    return 0;
}
