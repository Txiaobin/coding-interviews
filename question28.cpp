/*
请实现一个函数，用来判断一颗二叉树是不是对称的。
如果一颗二叉树和它的镜像一样，那么他是对称的，

        
xiaobin9652@163.com;
Xiaobin Tian;
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* p, TreeNode* q){
        if(p != nullptr && q != nullptr){
            if(p->val != q->val)
                return false;
            else
                return isSymmetrical(p->left, q->right) && isSymmetrical(p->right, q->left);
        }
        else if(p == nullptr && q == nullptr)
            return true;
        else
            return false;
    }
    bool isSymmetrical(TreeNode* pRoot){
        return isSymmetrical(pRoot, pRoot);
    }
};