#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int val_) : val(val_), next(NULL) {}
	ListNode(int val_, ListNode *next_) : val(val_), next(next_) {}
};

void insertAtTail(int val_, ListNode *head_) {
	while(head_->next != NULL)
		head_ = head_->next;
	head_->next = new ListNode(val_);
}

ListNode* insertAtHead(int val_, ListNode *head_) {
	ListNode *newHead = new ListNode(val_);
	newHead->next = head_;
	return newHead;
}

ListNode* reverseList(ListNode* head) {
	if(head == NULL)
		return head;
	if(head->next == NULL)
		return head;
	auto prev = head;
	auto cur = head->next;
	prev->next = NULL;
	while(cur != NULL) {
	    auto temp = cur->next;
	    cur->next = prev;
	    prev = cur;
	    cur = temp;
	}
	return prev;
}

// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
ListNode* reverseListsOfSizeK(ListNode* head, int k) {
	if(head == NULL)
		return head;
	vector<int> val;
	auto cur = head;
	while(cur != NULL) {
		val.push_back(cur->val);
		cur = cur->next;
	}
	for(int i = 0; i < val.size(); i += k)
		reverse(val.begin() + i, val.begin() + min((int)val.size(), i + k));
	reverse(val.begin(), val.end());
	cur = head;
	while(cur != NULL) {
		cur->val = val.back();
		val.pop_back();
		cur = cur->next;
	}
	return head;
}

ListNode* vectorToLinkedList(vector<int> a) {
	if(!a.size()) 
		return NULL;
	auto head = new ListNode(a.back());
	for(int i = a.size() - 2; i >= 0; i--)
		head = insertAtHead(a[i], head);
	return head;
}

void print(ListNode *head_) {
	while(head_ != NULL) {
		cout << head_->val << " ";
		head_ = head_->next;
	}
	cout << endl;
}

int getMiddleElement(ListNode *head) {
	if(head == NULL) return -1;
	int cnt = 0;
	auto cur = head;
	while(cur != NULL)
		cur = cur->next, cnt++;
	int middle = (cnt + 2)/2;
	cnt = 0;
	cur = head;
	while(cur != NULL) {
		cnt++;
		if(cnt == middle) return cur->val;
		cur = cur->next;
	}
	return 0;
}

int getSize(ListNode* head) {
	int cnt = 0;
	auto cur = head;
	while(cur != NULL) cnt++, cur = cur->next;
	return cnt;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	ListNode *head = vectorToLinkedList(vector<int>{1, 2, 3});
	
	print(head);
	return 0;
}
