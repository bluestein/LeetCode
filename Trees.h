#pragma once

// Definition for a binary tree node.
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Trees
{
public:
	int maxDepth(TreeNode* root); // #104
	TreeNode* invertTree(TreeNode* root); // #226
	bool isSameTree(TreeNode* p, TreeNode* q); // #100
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q); // #235
};

