/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

xiaobin9652@163.com;
Xiaobin Tian;
 */

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if(pNode == nullptr)
            return nullptr;
        TreeLinkNode *next = nullptr;
        if(pNode->right != nullptr){
            auto q = pNode->right;
            while(q->left != nullptr){
                q = q->left;
            }
            next = q;
        }
        else if(pNode->next != nullptr){
            auto parent = pNode->next;
            auto q = pNode;
            while(parent != nullptr && parent->right == q){
                parent = parent->next;
                q = q->next;
            }
            next = parent;
        }
        return next;
    }
};