/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<queue>
using namespace::std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> print;
		if(!root)
			return print;
		queue<TreeNode*> myqueue;
		auto p = root;
		myqueue.push(p);
		while(!myqueue.empty()){
			p = myqueue.front();
			myqueue.pop();
			print.push_back(p->val);
			if(p->left)
				myqueue.push(p->left);
			if(p->right)
				myqueue.push(p->right);
		}
		return print;
    }
};