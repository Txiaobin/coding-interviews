/*
*********************************************************************************
第一问：
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*********************************************************************************
第二问
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*********************************************************************************

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
  bool IsBalanced(TreeNode* pRoot, int *depth){
		if(pRoot == nullptr){
			*depth = 0;
			return true;
		}
		int NumOfLeft, NumOfRight;
		if(IsBalanced(pRoot->left, &NumOfLeft) && IsBalanced(pRoot->right, &NumOfRight)){
			int diff = NumOfLeft - NumOfRight;
			if(diff < 2 && diff > -2){
				*depth = 1 + (NumOfLeft > NumOfRight ? NumOfLeft:NumOfRight);
				return true;
			}
		}
		return false;
  }
public:
  int TreeDepth(TreeNode* pRoot){
		int num;
		if(pRoot == nullptr)
			return 0;
		int NumOfLeft = TreeDepth(pRoot->left);
		int NumOfRight = TreeDepth(pRoot->right);
		return (NumOfLeft > NumOfRight) ? ++NumOfLeft : ++NumOfRight;
  }

  bool IsBalanced_Solution(TreeNode* pRoot){
		  int depth = 0;
		  return IsBalanced(pRoot, &depth);
	}
};