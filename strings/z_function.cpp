#include <bits/stdc++.h>
using namespace std;
#define int long long int

// z[i] = length of longest prefix such that
// s.substr(i, z[i]) = s.substr(0, z[i]);
// s = pattern + "$" + text
struct z_function {
	vector<int> z;
	z_function() {}
	z_function(string s) {
		int n = s.length();
		z.assign(n, 0);
		z[0] = n;
		for(int i = 1, l = 0, r = 0; i < n; ++i) {
			if(i <= r) z[i] = min(r - i + 1, z[i - l]);
			while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
			if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
		}
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	return 0;
}
