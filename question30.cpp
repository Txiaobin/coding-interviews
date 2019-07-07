/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数.
时间复杂度应为O(1)。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<stack>
using namespace::std;

class Solution {
private:
	stack<int> data_stack;
	stack<int> min_stack;

public:
    void push(int value) {
        data_stack.push(value);
		if(min_stack.size() == 0 || min_stack.top() > value)
			min_stack.push(value);
		else
			min_stack.push(min_stack.top());
    }

    void pop() {
        data_stack.pop();
		min_stack.pop();
    }
    int top() {
        return data_stack.top();
    }
    int min() {
        return min_stack.top();
    }
};