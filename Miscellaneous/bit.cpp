#include <bits/stdc++.h>
using namespace std;
#define int long long int

template<int32_t base>
class Bit {
public:
	int64_t n, n_prev;
	vector<int> bits;
	void update() {
		if(n == n_prev) return;
		n_prev = n;
		bits.clear();
		int64_t nc = n;
		while(nc) bits.push_back(nc % base), nc /= base;
	}
	Bit(int64_t n_) {
		n = n_;
		update();
	}
	int operator[](int id) {
		return update(), id >= bits.size() ? 0 : bits[id];
	}
	int64_t count() {
		return update(), accumulate(bits.begin(), bits.end(), 0ll);
	}
	friend ostream& operator<<(ostream& os, Bit& obj) {
		obj.update();
		for(int i = (int)obj.bits.size() - 1; i >= 0; i--) 
			cout << (char)((obj.bits[i] <= 9) ? obj.bits[i] + '0' : (obj.bits[i] - 10 + 'A'));
		return os;
	}
};

using bit = Bit<16>;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	bit b(676);
	b.n++;
	cout << b;
	return 0;
}
