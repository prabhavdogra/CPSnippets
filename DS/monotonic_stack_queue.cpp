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

// ➼ We push and pop and maintain in the queue to maintain the following 2 properties
// • Whatever answer is required is stored in the front of the dequeue
// • All the elements in queue are monotonic in nature, i.e.
//   Strictly non increasing or non decreasing
template<typename T>
class MonotonicQueue {
public:
	deque<T> mn;
	deque<T> mx;
	void push(T val) {
		while(mn.size() && mn.back() > val)
			mn.pop_back();
		mn.push_back(val);
		while(mx.size() && mx.back() < val)
			mx.pop_back();
		mx.push_back(val);
	}
	void pop(T val) { // We need to pass the element that we need to delete
		if(mn.size() && mn.front() == val) {
			mn.pop_front();
		}
		if(mx.size() && mx.front() == val) {
			mx.pop_front();
		}
	}
	T getMin() {
		assert(mn.size());
		return mn.front();
	}
	T getMax() {
		assert(mx.size());
		return mx.front();
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	MonotonicStack<int> ms;
	MonotonicQueue<int> mq;
	return 0;
}
