#include "stdafx.h"
#include "Trees.h"

TreeNode* Trees::BuildHeap(vector<int> nums) // 0 means null
{
	TreeNode *root = NULL;
	if (nums.empty()) return root;
	root = new TreeNode(nums[0]);
	queue<TreeNode*> que;
	que.push(root);
	TreeNode *cur = NULL;
	for (int i = 1; i < nums.size(); ++i)
	{
		TreeNode* node = NULL;
		if (nums[i]) // nums[i] != 0, create node
		{
			node = new TreeNode(nums[i]);
			que.push(node);
		}
		if (i % 2) // left child
		{
			cur = que.front(), que.pop();
			cur->left = node;
		}
		else
		{
			cur->right = node;
		}
	}
	return root;

	/*TreeNode *root = NULL;
	if (nums.empty()) return root;
	root = new TreeNode(nums[0]);
	queue<TreeNode*> que;
	que.push(root);
	int len = 1;
	while (!que.empty() && len < nums.size())
	{
		int curLevel = que.size();
		while (curLevel-- && len < nums.size())
		{
			TreeNode* node = que.front();
			que.pop();
			for (int i = 0; i < 2; i++) // left and right node
			{
				TreeNode *tmp = nums[len] ? new TreeNode(nums[len]) : NULL;
				if (len % 2)
				{
					node->left = tmp;
				}
				else
				{
					node->right = tmp;
				}
				if (tmp) que.push(tmp);
				len++;
			}
		}

	}
	return root;*/
}

//each element a at index i has:
//1. children at indices 2i + 1 and 2i + 2.
//2. its parent floor((i - 1) / 2).
TreeNode* Trees::BuildHeap(vector<int> nums, int cur, int len) // 0 means null
{
	TreeNode *root = NULL;
	if (cur > len) return root;
	if (nums[cur]) root = new TreeNode(nums[cur]);
	if (root)
	{
		root->left = BuildHeap(nums, 2 * cur + 1, len);
		root->right = BuildHeap(nums, 2 * cur + 2, len);
	}
	return root;
}

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
	if (p == NULL && q == NULL) return true;
	return (p != NULL && q != NULL && p->val == q->val) &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
	
	/*
	if (p == NULL && q == NULL) return true;
	if (!(p && q) || p->val != q->val) return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	*/
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

//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//  recursive
bool symmetricHelper(TreeNode* left, TreeNode* right)
{
	if (!(left && right)) return left == right;
	if (left->val != right->val) return false;
	return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
}
bool Trees::isSymmetric(TreeNode* root)
{
	if (root == NULL) return true;
	return symmetricHelper(root->left, root->right);
}
// iterative
bool Trees::isSymmetric1(TreeNode* root)
{
	if (root == NULL) return true; 
	if (!(root->left && root->right)) return root->left == root->right;
	stack<TreeNode*> stk;
	stk.push(root->left), stk.push(root->right);
	while (!stk.empty())
	{
		TreeNode *node1 = stk.top();
		stk.pop();
		TreeNode *node2 = stk.top();
		stk.pop();

		if (node1->val != node2->val) return false;
		if (!(node1->left && node2->right) && !(node1->left == NULL && node2->right == NULL)) return false;
		if (!(node1->right && node2->left) && !(node1->right == NULL && node2->left == NULL)) return false;
		
		if (node1->left)
		{
			stk.push(node1->left), stk.push(node2->right);
		}
		if (node2->left)
		{
			stk.push(node1->right), stk.push(node2->left);
		}

	}
	return true;
}

//Given a binary tree, return the level order traversal of its nodes' values. 
//(ie, from left to right, level by level).
vector<vector<int>> Trees::levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	queue<TreeNode*> q1, q2;
	if (root) q1.push(root);
	while (!q1.empty() || !q2.empty())
	{
		q1 = q1.empty() ? q2 : q1;
		queue<TreeNode*> t;
		q2 = t;
		vector<int> level;
		while (!q1.empty())
		{
			TreeNode* node = q1.front();
			level.push_back(node->val);
			q1.pop();
			if (node->left) q2.push(node->left);
			if (node->right) q2.push(node->right);
		}
		result.push_back(level);
	}
	return result;
}

//Given a binary tree, return the bottom - up level order traversal of its nodes' values. 
//(ie, from left to right, level by level from leaf to root).
// breadth-first
vector<vector<int>> Trees::levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> result;
	queue<TreeNode*> q;
	if (root) q.push(root);
	while (!q.empty())
	{
		int lastLevel = q.size();
		vector<int> level;
		while (lastLevel--)
		{
			TreeNode* node = q.front();
			q.pop();
			level.push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		result.push_back(level);
	}
	reverse(result.begin(), result.end());
	return result;
}

//Given a binary tree and a sum, determine if the tree has a root - to - leaf path 
//such that adding up all the values along the path equals the given sum.
// depth-first-search
bool Trees::hasPathSum(TreeNode* root, int sum)
{
	if (!root) return false;
	// the leave val == the rest of sum
	if (root->val == sum && root->left == NULL && root->right == NULL) return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path 
//from the root node down to the nearest leaf node.
// breadth-first
int Trees::minDepth(TreeNode* root)
{
	queue<TreeNode*> q;
	if (root) q.push(root);
	int depth = 0;
	while (!q.empty())
	{
		depth++;
		int lastLevel = q.size();
		while (lastLevel--)
		{
			TreeNode* node = q.front();
			q.pop();
			if (!node->left && !node->right) return depth;
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
	}
	return depth;
}
// recursive
int Trees::minDepth1(TreeNode* root)
{
	if (!root) return 0;
	if (!root->left && !root->right) return 1;
	int lDepth = INT_MAX, rDepth = INT_MAX;
	if (root->left) lDepth = minDepth1(root->left) + 1;
	if (root->right) rDepth = minDepth1(root->right) + 1;
	return min(lDepth, rDepth);
}
