/*
输入一个链表，反转链表后，输出新链表的表头。

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
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode *dummyhead = new ListNode(0);
		dummyhead->next == nullptr;
		auto p = pHead, q = dummyhead->next;
		while(p!=nullptr){
			dummyhead->next = p;
			p = p->next;
			dummyhead->next->next = q;
            q = dummyhead->next;
		}
		return dummyhead->next;
    }
};