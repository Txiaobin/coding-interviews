/*
如果一个链表中包含环，如何找出环的入口节点？
如LeetCode题目 Linked List Cycle2，链接：https://leetcode-cn.com/problems/two-sum/solution/huan-xing-lian-biao-ii-by-leetcode/

解题思路：
思路一：哈希表，使用哈希表保存遍历过的节点，每次读取链表中一个节点后，与哈希表中元素进行比较，若存在相同的即有环。

思路二：Floyd 算法。
Floyd 的算法被划分成两个不同的阶段。在第一阶段，找出列表中是否有环，如果没有环，可以直接返回 null 并退出。否则，用相遇节点来找到环的入口。

阶段 1
这里我们初始化两个指针，快指针和慢指针。我们每次移动慢指针一步、快指针两步，直到快指针无法继续往前移动。
如果在某次移动后，快慢指针指向了同一个节点，我们就返回它。否则，我们继续，直到 while 循环终止且没有返回任何节点，这种情况说明没有成环，我们返回 null 。

环中的节点从 0 到 C-1 编号，其中 C 是环的长度。非环节点从 -F 到 -1 编号，其中 F 是环以外节点的数目。 
F次迭代以后，慢指针指向了 0 且快指针指向某个节点 h ，其中 h=F(mod)C 。这是因为快指针在 F 次迭代中遍历了 2F 个节点，且恰好有 F 个在环中。
继续迭代 C-h 次，慢指针显然指向第 C-h 号节点，而快指针也会指向相同的节点。原因在于，快指针从 h 号节点出发遍历了 2(C-h) 个节点。
h + 2(C−h)=2C−h
因此，如果列表是有环的，快指针和慢指针最后会同时指向同一个节点，因此被称为 相遇 。
(慢指针总是只走了F + C-h 个节点，即在环中未走满一圈；快指针可能在环中走了k圈)

阶段 2
给定阶段 1 找到的相遇点，阶段 2 将找到环的入口。首先我们初始化额外的两个指针： ptr1 ，指向链表的头， ptr2 指向相遇点。
然后，我们每次将它们往前移动一步，直到它们相遇，它们相遇的点就是环的入口，返回这个节点。
我们利用已知的条件：慢指针移动 1 步，快指针移动 2 步，来说明它们相遇在环的入口处。（下面证明中的 tortoise 表示慢指针，hare 表示快指针）
设F为环以外的节点的数目，a为在环中节点h之前的节点数目，b为在环中节点h之后的节点数目。
2⋅distance(tortoise)=distance(hare)
2(F+a)=F+k(a+b)+a
2F+2a=F+ka+kb+a
F=(k-1)(a+b)+b
因为 F=(k-1)(a+b)+b ，指针从 h 点出发和从链表的头出发，最后会遍历F个节点后在环的入口处相遇。

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
    ListNode* EntryNodeOfLoop(ListNode* pHead){
		if(pHead == nullptr || pHead->next == nullptr)
			return nullptr;
		ListNode *p = pHead, *q = pHead;
		while(q != nullptr && q->next != nullptr){
			q = q->next->next;
			p = p->next;
			if(p == q)
				break;
		}
		if(p != q){
			return nullptr;
		}
		q = pHead;
		while(p != q){
			p = p->next;
			q = q->next;
		}
		return p;
    }
};

