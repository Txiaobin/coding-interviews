/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(vin.size() == 0){
            return NULL;
        }
        TreeNode *head = new TreeNode(pre[0]);
        vector<int> pre_left, pre_right, vin_left, vin_right;
        int i = 0;
        for(; i < vin.size(); ++i){
            if(vin[i] == pre[0]){
                break;
            }
            pre_left.push_back(pre[i+1]);
            vin_left.push_back(vin[i]);
        }
        ++i;
        for(; i < vin.size(); ++i){
            pre_right.push_back(pre[i]);
            vin_right.push_back(vin[i]);
        }
        head->left = reConstructBinaryTree(pre_left, vin_left);
        head->right = reConstructBinaryTree(pre_right, vin_right);
        return head;
    }
};