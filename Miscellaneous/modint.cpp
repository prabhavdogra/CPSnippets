#include <bits/stdc++.h>
using namespace std;

template<uint32_t M_32>
class ModInt {
public:
	uint64_t data = 0;
	ModInt() {};
	ModInt(int64_t val) : data(Modulus(val)){};
	static uint64_t Modulus(int64_t val) { return ((val % M_32) < 0 ? (val % M_32) + M_32 : val % M_32); }

	ModInt& operator++() { return (++data == M_32) ? 0 : data, *this; }
	ModInt& operator--() { return --(data ? data : data = M_32), *this; }
	ModInt operator++(int) { 
		ModInt res = *this;
		return (++data == M_32) ? 0 : data, res;
	}
	ModInt operator--(int) { 
		ModInt res = *this;
		return --(data ? data : data = M_32), res;
	}
	friend ostream& operator<<(ostream& os, const ModInt& obj) {
		return (os << obj.data);
	}
	friend istream& operator>>(istream& is, ModInt& obj) {
		int64_t val;
		return (is >> val), obj.data = Modulus(val), is;
	}
	friend ModInt operator+(const ModInt& a, const ModInt& b) {
		ModInt res;
		return res.data = Modulus(a.data + b.data), res;
	}
	friend ModInt operator-(const ModInt& a, const ModInt& b) {
		ModInt res;
		return res.data = Modulus(a.data - b.data), res;
	}
	friend ModInt operator*(const ModInt& a, const ModInt& b) {
		ModInt res;
		return res.data = Modulus(Modulus(a.data) * Modulus(b.data)), res;
	}
	friend ModInt operator/(const ModInt& a, const ModInt& b) {
		auto [inv, gcd] = extgcd(b.data, M_32);
		assert(gcd == 1);
		return Modulus(a.data * inv);
	}
	ModInt& operator+=(ModInt a) { return *this = *this + a, *this; }
	ModInt& operator-=(ModInt a) { return *this = *this - a, *this; }
	ModInt& operator*=(ModInt a) { return *this = *this * a, *this; }
	ModInt& operator/=(ModInt a) { return *this = *this / a, *this; }
	template<typename T>
	void operator=(const T& a) { return (*this).data = Modulus(a), void(); }
	friend bool operator==(ModInt a, ModInt b) { return a.data == b.data; }
	friend bool operator!=(ModInt a, ModInt b) { return a.data != b.data; }
	static pair<uint64_t, uint64_t> extgcd(int64_t a, int64_t b) {
		array<int, 2> x{1, 0};
		while (b) swap(x[0] -= a / b * x[1], x[1]), swap(a %= b, b);
		return {x[0], a};
	}
};

template<typename T, typename S>
T pow(T x, S n) {
	T res = 1;
	while (n) {
		if (n & 1) res = (res * x);
		n = (n >> 1);
		x = (x * x);
	}
	return res;
}

const int MOD = 1 ? 1e9 + 7 : 998'244'353;
using mint = ModInt<MOD>;

int main() {
	mint a(12);
}
