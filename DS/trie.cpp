#include <bits/stdc++.h>
using namespace std;

template<typename NODE>
class Trie {
public:
	NODE* root;
	Trie() {
		root = new NODE();
	}
	void insert(string word) {
		NODE* cur = root;
		for(int i = 0; i < word.length(); i++) {
			if(!cur->containsKey(word[i])) {
				cur->put(word[i], new NODE());
			}
			cur = cur->get(word[i]);
		}
		cur->setAsLeaf();
	}
	bool search(string word) {
		NODE* cur = root;
		for(int i = 0; i < word.length(); i++) {
			if(!cur->containsKey(word[i])) {
				return false;
			}
			cur = cur->get(word[i]);
		}
		return cur->isLeaf();
	}
	bool startsWith(string prefix) {
		NODE* cur = root;
		for(int i = 0; i < prefix.length(); i++) {
			if(!cur->containsKey(prefix[i])) {
				return false;
			}
			cur = cur->get(prefix[i]);
		}
		return true;
	}
};

struct NODE {
public:
	bool is_leaf;
	vector<NODE*> next;
	NODE() {
		is_leaf = false;
		next = vector<NODE*>(26, NULL);
	}
	bool containsKey(char c) {
		return (next[c - 'a'] != NULL);
	}
	void put(char c, NODE* node) {
		next[c - 'a'] = node;
	}
	NODE* get(char c) {
		return next[c - 'a'];
	}
	void setAsLeaf() {
		is_leaf = true;
	}
	bool isLeaf() {
		return is_leaf;
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	Trie<NODE> x;
	x.insert("abcd");
	cout << x.search("abcd");
	return 0;
}
