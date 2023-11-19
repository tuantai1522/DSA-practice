//https://leetcode.com/problems/palindrome-linked-list/description/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverse(ListNode *head) {
	ListNode* cur = head;
	ListNode* prev = NULL;
	while (cur != NULL) {
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}
bool isPalindrome(ListNode* head) {
	if (head->next == NULL) return true;
	ListNode *slow = head;
	ListNode* fast = head;
	while (slow != NULL && fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	slow = reverse(slow);
	fast = head;
	while (slow != NULL) {
		if (slow->val != fast->val) return false;
		slow = slow->next;
		fast = fast->next;
	}
	return true;
}