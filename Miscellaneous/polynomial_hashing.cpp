#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Polynomial Rolling Hash Function
// = sigma(s[i] * p^i % M)
class polynomial_hash {
public:
	int p, mod;
	vector<int> p_pow, p_inv;
	int sz;
	string s;
	vector<int> forwardHash, backwardHash;
	polynomial_hash(string s_, int p_, int m_) {
		s = s_;
		p = p_;
		mod = m_;
		sz = s_.size();
		p_pow = p_inv = forwardHash = backwardHash = vector<int>(sz);
		precomputePowersOfP();
		precomputeHash();
	}
	void precomputePowersOfP() {
		p_pow[0] = p_inv[0] = 1;
		int f = modpow(p, mod - 2, mod);
		for(int i = 1; i < sz; i++) {
			p_pow[i] = p_pow[i - 1] * p % mod;
			p_inv[i] = p_inv[i - 1] * f % mod;
		}
	}
	void precomputeHash() {
		forwardHash[0] = s[0] - 'a' + 1;
		for(int i = 1; i < sz; i++) 
			forwardHash[i] = (forwardHash[i - 1] + p_pow[i] * (s[i] - 'a' + 1) % mod ) % mod;
		backwardHash[sz - 1] = s[sz - 1] - 'a' + 1;
		for (int i = sz - 2; i >= 0; i--) 
			backwardHash[i] = (backwardHash[i + 1] + p_pow[sz - i - 1] * (s[i] - 'a' + 1) % mod) % mod;
	}
	int getForwardHash(int start, int end) {
		if(start > end) swap(start, end);
		int q = forwardHash[end] - ((start == 0) ? 0 : forwardHash[start - 1]);
		if(q < 0) q += mod;
		return q * p_inv[start] % mod;
	}
	int getBackwardHash(int start, int end) {
		if(start > end) swap(start,end);
		int q = backwardHash[start] - ((end == sz - 1) ? 0 : backwardHash[end + 1]);
		if (q < 0) q += mod;
		return q * p_inv[sz - 1 - end] % mod;
	}
	int modpow(int64_t x, int n, int m) {
		int64_t res = 1;
		x = x % m;
		while(n) {
			if(n&1)
				res = (res * x) % m;
			n = (n >> 1);
			x = (x * x) % m;
		}
		return res;
	}
};

static const int P = 31; // Prime number roughly equal to the number of characters in the alphabet
static const int M = 1e9 + 9; // Prime number of modulus

polynomial_hash t("abcd", P, M);

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	return 0;
}
