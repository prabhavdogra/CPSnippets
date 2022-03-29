#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct manacher {
	string x;
	vector<int> odd, even;
	manacher(string s) {
		int n = (int)s.size();
		odd.assign(n, 0);
		even.assign(n, 0);
		for(int i = 0, l = 0, r = -1; i < n; ++i) {
			int len = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
			while(len <= i && i + len < n && s[i - len] == s[i + len]) ++len;
			odd[i] = len;
			--len;
			if(i + len > r) {
				l = i - len;
				r = i + len;
			}
		}
		for(int i = 0, l = 0, r = -1; i < n; ++i) {
			int len = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
			while(len < i && i + len < n && s[i - len - 1] == s[i + len]) ++len;
			even[i] = len;
			--len;
			if(i + len > r) {
				l = i - len - 1;
				r = i + len;
			}
		}
	}
	bool isPalindrome(int l, int r) {
		if((r - l + 1) % 2 == 1) {
			int center = (l + r)/2;
			if(odd[center] * 2 - 1 >= r - l + 1)
				return true;
		}
		else {
			int center = (l + r + 1)/2;
			if(even[center] * 2 >= r - l + 1)
				return true;
		}
		return false;
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	manacher m("abcd");
	return 0;
}
