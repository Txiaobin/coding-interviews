/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<stack>
using namespace::std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		bool result = false;
        if(pushV.size() != popV.size())
			return result;
		stack<int> mystack;
		int j = 0;
		int i=0;
		for(; i < popV.size(); ){
			while((j < pushV.size()) && (mystack.empty() || mystack.top() != popV[i])){
				mystack.push(pushV[j]);
				++j;
			}
			if(mystack.top() != popV[i])
				break;
			mystack.pop();
			++i;
		}
		if(mystack.empty() && (i == popV.size()))
			result = true;
		return result;
    }
};