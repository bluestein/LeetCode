#include "stdafx.h"
#include "Trees.h"

// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes 
// along the longest path from the root node down to the farthest leaf node.
int Trees::maxDepth(TreeNode* root)
{
	// Recursive solution
	if (root == NULL) return 0;
	int left = maxDepth(root->left) + 1;
	int right = maxDepth(root->right) + 1;
	return left > right ? left : right;
}


/*
Invert a binary tree.
4
/ \
2     7
/ \ / \
1   3 6   9   
----
to
----
4
/ \
7     2
/ \ / \
9   6 3   1
*/
TreeNode* Trees::invertTree(TreeNode* root)
{
	if (root == NULL) return NULL;
	if (root->left || root->right)
	{
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
	invertTree(root->left);
	invertTree(root->right);
	
	/* another way
	TreeNode *temp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(temp);
	*/

	return root;

	
}

//Given two binary trees, write a function to check if they are equal or not.
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
bool Trees::isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == NULL && q == NULL || (p != NULL && q != NULL && p->val == q->val))
		return true;
	else
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//Given a binary search tree(BST), 
//find the lowest common ancestor(LCA) of two given nodes in the BST.
//The lowest common ancestor is defined between two nodes v and w 
//as the lowest node in T that has both v and w as descendants
//(where we allow a node to be a descendant of itself).
TreeNode* Trees::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	while (true)
	{
		if ((root->val - p->val) * (root->val - q->val) <= 0) return root;
		else root = root->val - p->val > 0 ? root->left : root->right;
	}
}
