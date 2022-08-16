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
			cur->increasePrefixStringCnt();
		}
		cur->increaseLeafStringCnt();
	}
	int countWordsEqualTo(string word) {
		NODE* cur = root;
		for(int i = 0; i < word.length(); i++) {
			if(!cur->containsKey(word[i])) {
				return 0;
			}
			cur = cur->get(word[i]);
		}
		return cur->getLeafs();
	}
	int countWordsStartingWith(string prefix) {
		NODE* cur = root;
		for(int i = 0; i < prefix.length(); i++) {
			if(!cur->containsKey(prefix[i])) {
				return 0;
			}
			cur = cur->get(prefix[i]);
		}
		return cur->getPrefix();
	}
	void erase(string word) {
		NODE* cur = root;
		for(int i = 0; i < word.length(); i++) {
			if(cur -> containsKey(word[i])) {
				cur = cur->get(word[i]);
				cur->decreasePrefixStringCnt();
			}
			else {
				return;
			}
		}
		cur->decreaseLeafStringCnt();
	}
};

struct NODE {
public:
	int cntPrefix;
	int cntLeafs;
	vector<NODE*> next;
	NODE() {
		cntPrefix = 0;
		cntLeafs = 0;
		next = vector<NODE*>(26, NULL);
	}
	bool containsKey(char c) {
		return (next[c - 'a'] != NULL);
	}
	void increaseLeafStringCnt() {
		cntLeafs++;
	}
	void increasePrefixStringCnt() {
		cntPrefix++;
	}
	void decreaseLeafStringCnt() {
		cntLeafs--;
	}
	void decreasePrefixStringCnt() {
		cntPrefix--;
	}
	void put(char c, NODE* node) {
		next[c - 'a'] = node;
	}
	NODE* get(char c) {
		return next[c - 'a'];
	}
	int getLeafs() {
		return cntLeafs;
	}
	int getPrefix() {
		return cntPrefix;
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	Trie<NODE> x;

	return 0;
}
