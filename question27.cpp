/*
操作给定的二叉树，将其变换为源二叉树的镜像。
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
        
xiaobin9652@163.com;
Xiaobin Tian;
 */


using namespace::std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot == nullptr)
			return ;
		if(pRoot->left == nullptr && pRoot->right == nullptr)
			return ;
		auto p = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = p;
		if(pRoot->left != nullptr)
			Mirror(pRoot->left);
		if(pRoot->right != nullptr)
			Mirror(pRoot->right);
    }
};