/*
输入一个链表的头结点，从尾到头反过来打印出每个节点的值。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<stack>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> mylist;
        stack<int> mystack;
        auto p = head;
        while(p!=nullptr){
            mystack.push(p->val);
            p = p->next;
        }
        while(!mystack.empty()){
            mylist.push_back(mystack.top());
            mystack.pop();
        }
        return mylist;
    }
};