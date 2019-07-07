/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 
队列中的元素为int类型。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<stack>
#include<stdexcept>
using namespace::std;

class Solution
{
public:
    void push(int node) {
		stack1.push(node);
	}

    int pop() {
        if(stack2.empty()){
			while(!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if(stack2.empty()){
			throw runtime_error("queue is empty");
		}
		auto node = stack2.top();
		stack2.pop();
		return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};