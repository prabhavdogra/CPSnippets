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
    vector<int> primeFactors(int n) {
        vector<int> res;
        while(spf[n]) {
            int val = spf[n];
            res.push_back(val);
            while(n % val == 0)
                n /= val;
        }
        return res;
    }
    map<int, int> factorize(int n) {
        map<int, int> res;
        while(spf[n]) {
            int val = spf[n];
            while(n % val == 0)
                res[val]++, n /= val;
        }
        return res;
    }
    // Doesn't uses sieve()
    vector<int> divisors(int n) {
        vector<int> res;
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0)
                res.push_back(i);
        for(int i = sqrt(n); i > 1; i--)
            if(n % i == 0 && n/i != res.back())
                res.push_back(n/i);
        if(n > 1)
            res.push_back(n);
        return res;
    }
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	sieve<1'000'000> p;
    for(auto it: p.divisors(12))
        cout << it << " ";
    cout << '\n';

    for(auto it: p.primeFactors(420))
        cout << it << " ";
    cout << '\n';

	for(auto [key, freq]: p.factorize(60))
        cout << key << " " << freq << '\n';
    cout << '\n';

	return 0;
}
