/*
输入两棵二叉树A，B，判断B是不是A的子结构。
空树不是任意一个树的子结构

xiaobin9652@163.com;
Xiaobin Tian;
 */

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool Isequal(TreeNode* p, TreeNode* q){
		if(q == nullptr)
			return true;
		if(p == nullptr)
			return false;
		if(p->val!=q->val)
			return false;
		return Isequal(p->left, q->left) && Isequal(p->right, q->right);
	}

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		bool result = false;
		if (pRoot1 != nullptr || pRoot2 != nullptr){
			if(pRoot1->val==pRoot2->val)
				result = Isequal(pRoot1, pRoot2);
			if(!result)
				result = HasSubtree(pRoot1->left, pRoot2);
			if(!result)
				result = HasSubtree(pRoot1->right, pRoot2);
		}
        return result;
	}
};