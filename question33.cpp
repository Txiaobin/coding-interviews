/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;

class Solution {
	bool VerifySquence(vector<int> sequence, int begin, int end, int root){
		if(begin >= end){
			return true;
		}
		int begin1 = begin;
		while(sequence[begin] < sequence[root] && begin <=end){
			++begin;
		}
		if(begin > end)
			return true;
		int begin2 = begin;
		while(begin <=end){
			if(sequence[begin] < sequence[root]){
				return false;
			}
			++begin;
		}
		return VerifySquence(sequence, begin1, begin2-2, begin2-1) && VerifySquence(sequence, begin2, begin-2, begin-1);
	}
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size() == 0)
			return false;
		if(sequence.size() == 1)
			return true;
		return VerifySquence(sequence, 0, sequence.size()-2, sequence.size()-1);
    }
};