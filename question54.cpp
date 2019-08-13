/*
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如，(5，3，7，2，4，6，8) 中，按结点数值大小顺序第三小结点的值为4。

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
    TreeNode* KthNodeCore(TreeNode* pRoot, int &k){
        TreeNode* result = nullptr;
        if(pRoot->left != nullptr){
            result = KthNodeCore(pRoot->left, k);
        }
        if(result == nullptr){
            if(k == 1)
                result = pRoot;
            --k;
        }
        if(result == nullptr && pRoot->right != nullptr){
            result = KthNodeCore(pRoot->right, k);
        }
        return result;
    }
    TreeNode* KthNode(TreeNode* pRoot, int k){
        if(pRoot == nullptr || k == 0)
            return nullptr;
        return KthNodeCore(pRoot, k);
    }
};