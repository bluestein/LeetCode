#pragma once

// Definition for a list node.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
