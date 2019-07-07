/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<stdlib.h>
#include<stack>
using namespace::std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
		if(pRootOfTree == nullptr)
			return pRootOfTree;
		TreeNode *dummyHead = new TreeNode(0);
        TreeNode *pre = dummyHead, *cur = pRootOfTree;
		stack<TreeNode*> mystack;
		while((cur != nullptr) || (mystack.empty() == 0)){
			while(cur != nullptr){
				mystack.push(cur);
				cur = cur->left;
			}
			if(mystack.empty() == 0){
				cur = mystack.top();
				mystack.pop();
				pre->right = cur;
				cur->left = pre;
				pre = cur;
				cur = cur->right;
			}
		}
		cur = dummyHead->right;
		cur->left = nullptr;
		free(dummyHead);
		return cur;
    }
};