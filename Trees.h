#pragma once
#include <stack>
#include <vector>
#include <queue>
#include "Structs.h"
using namespace std;

class Trees
{
public:
	static TreeNode* BuildHeap(vector<int>);
	static TreeNode* BuildHeap(vector<int>, int, int);
	int maxDepth(TreeNode* root); // #104
	TreeNode* invertTree(TreeNode* root); // #226
	bool isSameTree(TreeNode* p, TreeNode* q); // #100
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q); // #235
	bool isSymmetric(TreeNode* root); // #101 recursive
	bool isSymmetric1(TreeNode* root); // #101 iterative
	vector<vector<int>> levelOrder(TreeNode* root); // #102
	vector<vector<int>> levelOrderBottom(TreeNode* root); // #107
	bool hasPathSum(TreeNode* root, int sum); // #112
	int minDepth(TreeNode* root); // #111 iterative
	int minDepth1(TreeNode* root); // #111 recursive
};

