/*
请实现两个函数，分别用来序列化和反序列化二叉树。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<string>
#include<cstdlib>
#include<stack>
using namespace::std;

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
    void Serialize(TreeNode *root, string& str){
        if(root == nullptr){
            str += '$';
            return;
        }
        char* temp;
        sprintf(temp,"%d", root->val);
        str += *temp;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
    char* Serialize(TreeNode *root) {    
        if(root == nullptr)
            return nullptr;
        string str;
        Serialize(root, str);
        char *result = new char[str.length()+1];
        for(int i = 0; i < str.length(); ++i){
            result[i] = str[i];
        }
        result[str.length()] = '\0';
        return result;
    }

    TreeNode* Deserialize(char **str){
        if(**str == '$'){
            ++(*str);
            return nullptr;
        }
        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + atoi(*str);
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else 
            ++(*str);
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
    TreeNode* Deserialize(char *str) {
        if(str == nullptr)
            return nullptr;
        TreeNode *result = Deserialize(&str);
        return result;
    }
};