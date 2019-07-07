/*
输入一个链表，输出该链表中倒数第k个结点。

xiaobin9652@163.com;
Xiaobin Tian;
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if(pListHead == nullptr || k < 1)
			return nullptr;
		ListNode *p = pListHead, *q = pListHead;
		for(int i = 1; i < k; ++i){
			if(p->next == nullptr)
				return nullptr;
			p = p->next;
		}
		while(p->next != nullptr){
			p = p->next;
			q = q->next;
		}
		return q;
    }
};