#include <bits/stdc++.h>
using namespace std;
#define int long long int

int64_t MOD = LLONG_MAX;
int64_t MOD = 1e9 + 7;
template<typename T>
struct matrix {
	int rows, columns;
	vector<T> data_;
	matrix() {}
	matrix(int n__, int m__) : rows(n__), columns(m__), data_(rows * columns, 0) {}
	matrix(vector<vector<int>> mat_) : rows(mat_.size()), columns(mat_[0].size()), data_(rows * columns, 0) {
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				data_[i * columns + j] = mat_[i][j];
	}
	typename vector<T>::iterator operator[](int i) {
		return data_.begin() + i * columns;
	}
	typename std::vector<T>::const_iterator operator[](int i) const {
		return data_.begin() + i * columns;
	}
	static matrix<T> identity(int n__) {
		matrix<T> res(n__, n__);
		for(int i = 0; i < n__; i++)
			res[i][i] = 1;
		return res;
	}
	friend matrix<T> operator + (const matrix<T> &a, const matrix<T> &b) {
		assert(a.rows == b.rows && a.columns == b.columns);
		matrix res(a.rows, a.columns);
		for(int i = 0; i < a.rows; i++)
			for(int j = 0; j < a.columns; j++)
				res[i][j] = (a[i][j] + b[i][j]) % MOD;
		return res;
	}
	friend matrix<T> operator - (const matrix<T> &a, const matrix<T> &b) {
		assert(a.rows == b.rows && a.columns == b.columns);
		matrix res(a.rows, a.columns);
		for(int i = 0; i < a.rows; i++)
			for(int j = 0; j < a.columns; j++)
				res[i][j] = (a[i][j] - b[i][j]) % MOD;
		return res;
	}
	friend matrix<T> operator * (const matrix<T> &a, const matrix<T> &b) {
		assert(a.columns == b.rows);
		matrix res(a.rows, b.columns);
		for(int i = 0; i < a.rows; i++)
			for(int k = 0; k < a.columns; k++)
				for(int j = 0; j < b.columns; j++)
					res[i][j] = (res[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
		return res;
	}
	template<typename S>
	friend matrix<T> operator * (const S &a, const matrix<T> &b) {
		matrix res(b.rows, b.columns);
		for(int i = 0; i < b.rows; i++)
			for(int j = 0; j < b.columns; j++)
				res[i][j] = b[i][j] * a;
		return res;
	}
	template<typename S>
	friend matrix<T> operator * (const matrix<T> &b, const S &a) {
		matrix res(b.rows, b.columns);
		for(int i = 0; i < b.rows; i++)
			for(int j = 0; j < b.columns; j++)
				res[i][j] = b[i][j] * a;
		return res;
	}
	friend bool operator == (const matrix<T> &a, const matrix<T> &b) {
		assert(a.rows == b.rows && a.columns == b.columns);
		for(int i = 0; i < a.rows; i++)
			for(int j = 0; j < a.columns; j++)
				if(a[i][j] != b[i][j])
					return false;
		return true;
	}
	matrix<T>& operator += (const matrix<T> &a) {
		return *this = *this + a;
	}
	matrix<T>& operator -= (const matrix<T> &a) {
		return *this = *this - a;
	}
	matrix<T>& operator *= (const matrix<T> &a) {
		return *this = *this * a;
	}
	matrix<T> pow(int64_t e) const {
		assert(rows == columns);
		if(e == 0) return identity(rows);
		if(e&1) return *this * pow(e - 1);
		return (*this * *this).pow(e / 2);
	}
	matrix<T> transpose() const {
		matrix<T> res(columns, rows);
		for(int i = 0; i < columns; i++)
			for(int j = 0; j < rows; j++)
				res[i][j] = data_[j * columns + i];
		return res;
	}
	void print() {
		cerr << columns << '\n';
		for(int i = 0; i < data_.size(); i++) {
			cerr << data_[i] << " ";
			if(columns && (i + 1) % columns == 0)
				cerr << '\n';
		}
	}
};

// Declaration:              matrix<int> a(rows, columns);
// Initialising:             matrix<int> a({
//                               {0, 1, 2},
//                               {3, 4, 5},
//                           });
// To access:                a[row][column];
// Rows in the matrix:       a.rows
// Columns in the matrix:    a.columns
// Identity square matrix:   identity(n);
// Matrix Addition:          c = a + b;
// Matrix Multiplicaton:     res = a * b;
// Scalar Multiplication:    res = a * 2;
// Matrix Exponentiation:    res = a.pow(n);
// Transpose Matrix:         res = a.transpose();
// Print Matrix:             a.print();

// NOTE:
//  • Remember to set MOD, MOD = LLONG_MAX; in case of no mod
//  • +, -, *, +=, -=, *=, == -> Overloaded Operators
//  • Make sure to matrix<double> if you're multiplying by a double scalar

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	matrix<int> a(n, m);
	
	return 0;
}
