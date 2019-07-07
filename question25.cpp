/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<stack>
#include<stdexcept>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        ListNode *dummyhead = new ListNode(0);
		ListNode *r = dummyhead;
		ListNode *p = pHead1, *q = pHead2;
		while(p != nullptr && q != nullptr){
			if(p->val < q->val){
				r->next = p;
				p = p->next;
				r = r->next;
			}
			else{
				r->next = q;
				q = q->next;
				r = r->next;
			}
		}
		if(p == nullptr)
			r->next = q;
		if(q == nullptr)
			r->next = p;
		return dummyhead->next;
    }
};