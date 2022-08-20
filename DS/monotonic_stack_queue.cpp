#include <bits/stdc++.h>
using namespace std;

// • We store {element, answerForCurrentStack}
// • Push in stack the pair of {element, the minimum/maximum of all the elements present in the stack}
//   Recurrence:
//   ➼ stack.push({element, max(stack.top().second, element)})
template<typename T>
class MonotonicStack {
public:
	stack<pair<T, T>> mn;
	stack<pair<T, T>> mx;
	void push(T val) {
		if(mx.size()) {
			mn.push({val, min(mn.top().second, val)});
			mx.push({val, max(mx.top().second, val)});
		}
		else {
			mn.push({val, val});
			mx.push({val, val});
		}
	}
	void pop() {
		assert(mn.size());
		assert(mx.size());
		mn.pop();
		mx.pop();
	}
	T getMin() {
		assert(mn.size());
		return mn.top().second;
	}
	T getMax() {
		assert(mx.size());
		return mx.top().second;
	}
};

// ➼ We maintain 2 stacks, one for pushing and one for popping
// • In the pushing stack we push {element, max/min/gcd of elements present in the stack}
// • We pop from the popping stack, if at any time the stack s2 is empty, we move all elements from s1 to s2 
//   (which essentially reverses the order of those elements)
// • Finding max/min/gcd just involves finding the max/min/gcd of both stacks
template<typename T, typename DATA>
class MonotonicQueue {
public: 
	stack<pair<T, DATA>> s1, s2;
	void push(T val) {
		DATA x;
		if(s1.size()) x = s1.top().second;
		s1.push({val, combine(x, DATA(val))});
	}
	void pop() {
		if(!s2.size()) {
			assert(s1.size());
			s2.push({s1.top().first, DATA(s1.top().first)});
			s1.pop();
			while(s1.size()) {
				auto val = s1.top().first;
				s2.push({val, combine(s2.top().second, DATA(val))});
				s1.pop();
			}
		}
		s2.pop();
	}
	DATA getResult() {
		DATA data1;
		if(s1.size()) data1 = s1.top().second;
		DATA data2;
		if(s2.size()) data2 = s2.top().second;
		return combine(data1, data2);
	}
};

struct DATA {
	int mn, mx, g;
	DATA() {
		mn = 1e18;
		mx = -1e18;
		g = 0;
	}
	DATA(int x) {
		mn = x;
		mx = x;
		g = x;
	}
};

DATA combine(DATA a, DATA b) {
	DATA res;
	res.mn = min(a.mn, b.mn);
	res.mx = max(a.mx, b.mx);
	res.g = gcd(a.g, b.g);
	return res;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	MonotonicStack<int> ms;
	MonotonicQueue<int, DATA> mq;
	return 0;
}
