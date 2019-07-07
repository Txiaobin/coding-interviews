/*
输入两个链表，找出它们的第一个公共结点。

xiaobin9652@163.com;
Xiaobin Tian;
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	int lengthoflist(ListNode *Head){
		int length = 0;
		auto p = Head;
		while(p != nullptr){
			p = p->next;
			++length;
		}
		return length;
	}
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;
		int length1 = lengthoflist(pHead1);
		int length2 = lengthoflist(pHead2);
		ListNode * p = pHead1, *q = pHead2;
		int lengthdif = length1 - length2;
		if(length1 < length2){
			q = pHead1;
			p = pHead2;
			lengthdif = length2 - length1;
		}
		for(int i = 0; i < lengthdif; ++i)
			p = p->next;
		while(p != nullptr && q != nullptr && p->val != q->val){
			p = p->next;
			q = q->next;
		}
		return p;
    }
};