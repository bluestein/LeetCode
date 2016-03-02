#include "stdafx.h"
#include "LinkList.h"
#include <vector>
using namespace std;


LinkList::LinkList()
{
}


LinkList::~LinkList()
{
}

ListNode* LinkList::genList(int len) {
	if (len == 0) return NULL;
	ListNode *head = new ListNode(1);
	if (len == 1) return head;
	ListNode *cur = head;
	for (int i = 2; i <= len; i++) {
		ListNode *tmp = new ListNode(i);
		cur->next = tmp;
		cur = tmp;
	}
	return head;
}

void LinkList::printList(ListNode* head) {
	if (head == NULL) printf("NULL List!\n");
	while (head != NULL)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
}

// 给定一个单向链表，将下标为奇数的节点放在一起，后面接偶数节点。试着在原链表上完成。
// 其中，奇偶节点的顺序跟原来一致，第一个是奇节点。
// 要求：O(1) space, O(n) time
// 算法：通过改变指针，生成两个链表，分别是odd，even，然后连接起来即可。
// 如， [1,2,3,4,5], odd: [1,3,5], even: [2,4], => result: odd->even
ListNode* LinkList::oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* even_head = head->next;
	while (even != NULL && even->next != NULL)
	{
		odd->next = even->next;
		odd = even->next;
		even->next = odd->next;
		even = odd->next;
	}
	odd->next = even_head;
	return head;
}

// 反转一个链表
ListNode* LinkList::reverseList(ListNode* head) {
	if (head == NULL) return head;
	ListNode* pre = NULL;
	ListNode* cur = head;
	while (cur != NULL)
	{
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}

// 反转一个链表在区间 [m, n] (1 <= m <= n <= List.length) 部分。
// 要求：in-place， one-pass
// 算法1：one-loop
//	分两种情况：下面 "->" 表示连接。
//	case1: m = 1 从第一个开始反转，然后 head = Node(n), Node(m)->Node(n + 1);
//	case2: m > 1 从m个开始反转，然后 Node(m - 1)->Node(n)， Node(m)->Node(n + 1);
// 算法2：two-loop
//	先定位到 m - 1，然后开始反转。考虑到 m = 1的情况，创建一个head节点。
ListNode* LinkList::reverseBetween1(ListNode* head, int m, int n) {
	if (m == n) return head;
	// 1： one-loop
	int cnt = 1;
	ListNode *cur = head, *left = NULL, *tail = NULL, *pre = NULL;
	while (cnt <= n) {
		if (m == 1 && cnt == 1) { // case1: m = 1
			tail = cur;
			pre = tail;
			cur = cur->next;
			cnt++;
		}
		else if (cnt == m - 1 ) {// case2: m > 1
			left = cur;
			tail = cur->next;
			pre = tail;
			cur = cur->next;
			cnt ++;
		}
		// 反转
		if (cnt > m) { // 开始反转
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
			cnt++;
		}
		else { // 跳过不需反转元素
			cnt++;
			cur = cur->next;
		}
	}
	if (m == 1) {
		head = pre; // head = Node(n)
	}
	else {
		left->next = pre; // Node(m - 1)->Node(n)
	}
	tail->next = cur; // Node(m)->Node(n + 1)
	return head;
}

// 2: two-loop
ListNode* LinkList::reverseBetween2(ListNode* head, int m, int n) {
	if (m == n) return head;
	ListNode* head_new = new ListNode(0);
	head_new->next = head;
	ListNode *left = head_new, *pre, *cur;
	for (int i = 0; i < m - 1; i++)
		left = left->next; //skip
	pre = left->next;
	cur = pre->next;
	for (int i = 0; i < n - m; i++) { //reverse
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	left->next->next = cur; // left link to right
	left->next = pre;
	ListNode *temp = head_new;
	head_new = head_new->next;
	free(temp);
	return head_new;
}

// Given a linked list, remove the nth node from the end of list and return its head.
// For example,
//	Given linked list : 1->2->3->4->5, and n = 2.
//	After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
//	Given n will always be valid.
//	Try to do this in one pass.
ListNode* LinkList::removeNthFromEnd(ListNode* head, int n) {
	if (head->next == NULL || head == NULL) return NULL;
	ListNode *pre = NULL, *target = head, *cur = head;
	while (n-- > 0)
	{
		cur = cur->next;
	}
	if (cur == NULL) { // delete head
		ListNode *tmp = head;
		head = head->next;
		free(tmp);
		return head;
	}
	while (cur != NULL) {
		pre = target;
		target = target->next;
		cur = cur->next;
	}
	ListNode *tmp = target;
	pre->next = target->next;
	free(tmp);
	return head;
}

// Remove all elements from a linked list of integers that have value val.
// Example
//	Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//	Return: 1 --> 2 --> 3 --> 4 --> 5
// S1：
//	new a node，so all case can be treated as "inner delete"
// S2:
//	two pointers, pre and cur. use a while loop to deal with "head delete".
ListNode* LinkList::removeElements(ListNode* head, int val) {
	//S1
	/*ListNode* head_new = new ListNode(0);
	head_new->next = head;
	ListNode *pre = head_new, *cur = head;
	while (cur != NULL) {
		if (cur->val == val) {
			ListNode* tmp = cur;
			pre->next = cur->next;
			cur = cur->next;
			free(tmp); // free space
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	return head_new->next;*/

	//S2
	while (head != NULL && head->val == val)
		head = head->next;
	if (head == NULL) return NULL; // case: [1,1,1] and 1
	ListNode *pre = head, *cur = head->next;
	while (cur != NULL)
	{
		if (cur->val == val) {
			ListNode* tmp = cur;
			pre->next = cur->next;
			cur = cur->next;
			free(tmp); // free space
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}

// Given a sorted linked list, delete all duplicates such that each element appear only once.
ListNode* LinkList::deleteDuplicates(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode *pre = head, *cur = head->next;
	while (cur != NULL) {
		if (cur->val == pre->val) {
			ListNode* tmp = cur;
			pre->next = cur->next;
			cur = cur->next;
			free(tmp); // free space
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}
// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.
ListNode* LinkList::mergeTwoLists1(ListNode* l1, ListNode* l2) {
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	while (l1 && l2)
	{
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1) cur->next = l1;
	if (l2) cur->next = l2;
	ListNode *temp = head;
	head = head->next;
	free(temp);
	return head;

	// no fake head
	/*if (!l1) return l2;
	if (!l2) return l1;
	if(l1->val > l2->val){
	    ListNode *temp = l1;
	    l1 = l2, l2 = temp;
	}
	ListNode *head = l1;
	ListNode *cur = head;
	l1 = l1->next;
	while (l1 && l2)
	{
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
	    }
		else {
		    cur->next = l2;
		l2 = l2->next;
	    }
		cur = cur->next;
	}
	if (l1) cur->next = l1;
	if (l2) cur->next = l2;
	return head;*/
}

//recursive
ListNode* LinkList::mergeTwoLists2(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;
	if (l1->val <= l2->val) {
		l1->next = mergeTwoLists2(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists2(l1, l2->next);
		return l2;
	}
}

// Write a function to delete a node (except the tail) in a singly linked list,
// given only access to that node.
// S: delete the node->next!
void LinkList::deleteNode(ListNode* node) {
	ListNode *nxt = node->next;
	node->val = nxt->val;
	node->next = nxt->next;
	free(nxt);
}