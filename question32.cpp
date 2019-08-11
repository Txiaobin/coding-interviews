/*
题目一：不分行的从上往下打印出二叉树的每个节点，同层节点从左至右打印。

题目二：分行的从上到下打印二叉树。同一层按照从左到右顺序打印，每一层打印一行。

题目三：实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

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
//题目一：
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

//题目二：
	vector<int> PrintFromTopToBottom(TreeNode* root) {

    }

//题目三：
	vector<vector<int> > Print(TreeNode* pRoot) {
        
    }
};