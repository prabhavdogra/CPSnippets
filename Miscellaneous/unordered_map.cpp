#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long int

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class K, class V> using safe_map = gp_hash_table<K, V, custom_hash>;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (auto &it: a) cin >> it;
	ht<int, pair<int, int>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int req = x - a[i] - a[j];
			if (mp.find(req) != mp.end()) {
				cout << i + 1 << " " << j + 1 << " " << mp[req].first << " "
					 << mp[req].second;
				return 0;
			}
		}
		for (int j = i - 1; j >= 0; j--) mp[a[i] + a[j]] = {i + 1, j + 1};
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
