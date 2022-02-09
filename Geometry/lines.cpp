#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	map<pair<int, int>, set<int>> slope;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i + 1; j++) {
			int dx = x[i] - x[j], dy = y[i] - y[j];
			int g = abs(__gcd(dx, dy));
			if(dx < 0 || (dx == 0 && dy < 0))
				dx *= -1, dy *= -1;
			dx /= g; dy /= g;
			// Required to check parallel or concurrent
			int c = (dy * x[i]) - (dx * y[i]);
			slope[{dx, dy}].insert(c);
		}
	}
	return 0;
}
