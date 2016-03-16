#pragma once
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include "Nodes.h"
using namespace std;

class Trees
{
public:
	static TreeNode* BuildHeap_i(vector<int>); // iterative
	static TreeNode* BuildHeap_r(vector<int>, int, int); // recursive
	int maxDepth(TreeNode* root); // #104
	TreeNode* invertTree(TreeNode* root); // #226
	bool isSameTree(TreeNode* p, TreeNode* q); // #100
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q); // #235
	bool isSymmetric_r(TreeNode* root); // #101 recursive
	bool isSymmetric_i(TreeNode* root); // #101 iterative
	vector<vector<int>> levelOrder(TreeNode* root); // #102
	vector<vector<int>> levelOrderBottom(TreeNode* root); // #107
	bool hasPathSum(TreeNode* root, int sum); // #112
	int minDepth_i(TreeNode* root); // #111 iterative
	int minDepth_r(TreeNode* root); // #111 recursive
	vector<string> binaryTreePaths_r(TreeNode* root); // #257 recursive
	vector<string> binaryTreePaths_i(TreeNode* root); // #257 iterative
};

