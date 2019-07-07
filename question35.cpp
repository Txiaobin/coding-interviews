/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空

xiaobin9652@163.com;
Xiaobin Tian;
 */

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
		auto p = pHead;
		while(p != nullptr){
			RandomListNode* q = new RandomListNode(p->label);
			q->next = nullptr;
			q->next = p->next;
			p->next = q;
			p = q->next;
		}
		p = pHead;
		RandomListNode* q;
		while(p != nullptr){
			q = p->next;
			if(p->random)
				q->random = p->random->next;
			p = q->next;
		}
		p = pHead;
		q = nullptr;
		RandomListNode* dummyHead = nullptr;
		if(p != nullptr){
			dummyHead = q = p->next;
			p->next = q->next;
			p = q->next;
		}
		while(p != nullptr){
			q->next = p->next;
			q = q->next;
			p->next = q->next;
			p = q->next;
		}
		return dummyHead;
    }
};