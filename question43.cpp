/*
求出任意非负整数区间中 1 出现的次数（从1 到 n 中1出现的次数）。
例如：1~13 中包含 1 的数字有 1、10、11、12、13 因此共出现 6 次


xiaobin9652@163.com;
Xiaobin Tian;
 */

using namespace::std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){
		int sum = 0;
		for(int i = 0; i <= n; ++i){
			auto num = i;
			while(num != 0){
				int temp = num % 10;
				if(temp == 1)
					++sum;
				num /= 10;
			}
		}
		return sum;
    }
};