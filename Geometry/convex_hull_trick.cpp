#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Works only for monotonic functions

struct line {
	int m, c;
	line(int slope, int yIntercept) {
		m = slope;
		c = yIntercept;
	}

	int val(int x) { return m * x + c; }
	
	// y1 = m1 * x + c1
	// y2 = m2 * x + c2
	// m1 * x + c1 = m2 * x + c2
	// x = ceiling((c2 - c1)/(m1 - m2))
	int intersect(line y) {
		return (y.c - c + m - y.m - 1)/(m - y.m);
	}
};

class ConvexHullTrick {
public:
	// {line, x_coordinate}
	// line dq[i].first is optimal choice in the range [dq[i].second, dp[i + 1].second)
	deque<pair<line, int>> dq;
	bool isNewBetter(int oldXintercept, int newXIntercept);
	void insert(int m, int c) {
		line newLine(m, c);
		if(!dq.size())
			return dq.emplace_back(newLine, 0), void(); // Change 0 to INF for max
		while(dq.size() && isNewBetter(dq.back().second, dq.back().first.intersect(newLine)))
			dq.pop_back();
		dq.emplace_back(newLine, dq.back().first.intersect(newLine));
	}
	// Not clearing deque 
	int query(int x) {
		auto qry = *lower_bound(dq.rbegin(), dq.rend(),
								make_pair(line(0, 0), x),
								[&](const pair<line, int> &a, const pair<line, int> &b) {
									return a.second > b.second;
								});
		return qry.first.val(x);
	}
	// Clearing deque (Queries in increasing order of x)
	int query2(int x) {
		while(dq.size() > 1)
			if(dq[1].second <= x) dq.pop_front();
			else break;
		return dq[0].first.val(x);
	}
};

bool ConvexHullTrick::isNewBetter(int oldXintercept, int newXIntercept) {
	return (oldXintercept >= newXIntercept); // Note the = Case
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int slope, constant, xcoordinate;
	ConvexHullTrick t;
	t.insert(slope, constant);
	t.query(xcoordinate);
}
