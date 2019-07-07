/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
注意: 在返回值的list中，数组长度大的数组靠前

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<stack>
#include<stdexcept>
using namespace::std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	vector<int> temp;
	vector<vector<int> > allpath;
	void FindonePath(TreeNode* root, int expectNumber, int num){
		num += root->val;
		temp.push_back(root->val);
		if(((root->left == nullptr) && (root->right == nullptr)) && (num == expectNumber))
			allpath.push_back(temp);
		if(root->left != nullptr)
			FindonePath(root->left, expectNumber, num);
		if(root->right != nullptr)
			FindonePath(root->right, expectNumber, num);
		temp.pop_back();
	}

public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int> > path;
		if(root == nullptr)
			return path;
		int num = 0;
		FindonePath(root, expectNumber, num);
		return allpath;
    }
};