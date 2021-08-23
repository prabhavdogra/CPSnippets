#include <bits/stdc++.h>
using namespace std;
#define int long long int

// O(n log log n)
template <int SZ = 1'000'000>
struct sieve {
	vector<bool> isPrime;
	vector<int> prime, spf;
	sieve() {
		spf.resize(SZ + 1);
		isPrime.assign(SZ + 1, true);
		isPrime[0] = isPrime[1] = false;
		for(int i = 2; i <= SZ; i++) {
			if(isPrime[i])
				prime.push_back(i), spf[i] = i;
			for(int j = 0; j < prime.size() && i * prime[j] <= SZ && prime[j] <= spf[i]; j++) {
				isPrime[i * prime[j]] = false;
				spf[i * prime[j]] = prime[j];
			}
		}
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	sieve<1'000'000> p;
	
	return 0;
}
