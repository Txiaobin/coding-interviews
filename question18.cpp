/*
删除链表节点
题目一：
给定单向链表的头指针和一个节点指针，定义一个函数在 O(1) 时间内删除该节点。

题目二：
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

xiaobin9652@163.com;
Xiaobin Tian;
 */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead, ListNode* p){
        if(pHead == nullptr || p == nullptr)
            return nullptr;
        if(p->next != nullptr){
            auto q = p->next;
            p->val = q->val;
            p->next = q->next;
            delete q;
        }
        else if(pHead == p){
            delete p;
            p = nullptr;
            pHead = nullptr;
        }
        else{
            auto q = pHead;
            while(q->next != p){
                q = q->next;
            }
            q->next = p->next;
            delete p;
            p = nullptr;
        }
    }

    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = pHead;
        auto p = pHead, pre = dummyHead;
        while(p != nullptr && p->next != nullptr){
            if(p->val == p->next->val){
                int val = p->val;
                while(p != nullptr && p->val == val){
                    auto q = p->next;
                    delete p;
                    p = nullptr;
                    p = q;
                }
                pre->next = p;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return dummyHead->next;
    }
};