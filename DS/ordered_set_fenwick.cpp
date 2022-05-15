#include <bits/stdc++.h>
using namespace std;
#define int long long int
#ifdef prabhav_
	#include "Headers/debug.cpp"
#endif

// Ordered Mutiset
template<typename T>
struct BIT {
public:
	int n, sz = 0;
	vector<T> btree;
	vector<int> freq;
	BIT(int mxVal) {
		n = mxVal;
		btree = vector<T> (mxVal + 2);
		freq = vector<int> (mxVal + 2);
	}
	void build(vector<T> &a) {
		for(int i = 0; i < n; i++)
			update(i, a[i]);
	}
	void update(int id, T val) {
		id++;
		while(id <= n) {
			btree[id] += val;
			id = id + (id & (-id));
		}
	}
	void insert(int val) {
		update(val - 1, 1);
		freq[val]++;
		sz++;
	}
	void erase(int val) {
		update(val - 1, -1);
		freq[val]--;
		sz--;
	}
	int get(int start, int end) { return get(end) - (start - 1 >= 0 ? get(start - 1) : 0); }
	int get(int id) {
		id++;
		int sm = 0;
		while(id > 0 && id < btree.size()) {
			sm += btree[id];
			id = id - (id & (-id));
		}
		return sm;
	}
	int order_of_key(int val) { return get(val - 2); }
	int find_by_order(int id) {
		if(id >= get(n - 1)) return -1;
		id += 1;
		int start = 0, end = btree.size() - 1, ans;
		while(start <= end) {
			int mid = start + (end - start)/2;
			int midId = get(mid - 1);
			if(midId >= id) end = mid - 1, ans = mid;
			else start = mid + 1;
		}
		return ans;
	}
	int size() { return sz; }
	void print() {
		int val = 0;
		vector<int> v;
		for(auto it: freq) {
			for(int i = 0; i < it; i++) v.push_back(val);
			val++;
		}
		d(v);
	}
};

BIT<int> os;
//  .insert(val)
//  .erase(iter/val)
//  .order_of_key(k) -> Number of items strictly smaller than k
//  .find_by_order(k) -> K-th element in a set (counting from zero)
//  .print() 
