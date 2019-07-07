/*
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if(index<=0)
			return 0;
		vector<int> uglynumber = {1};
		int next = 1;
		int next2number = 0, next3number = 0, next5number = 0;
		while(next < index){
			int min = (uglynumber[next2number] * 2 < uglynumber[next3number] * 3 ) ? uglynumber[next2number] * 2 : uglynumber[next3number] * 3;
			min = (min < uglynumber[next5number] * 5) ? min : uglynumber[next5number] * 5;
			uglynumber.push_back(min);
			if(uglynumber[next2number] * 2 <= uglynumber[next])
				++next2number;
			if(uglynumber[next3number] * 3 <= uglynumber[next])
				++next3number;
			if(uglynumber[next5number] * 5 <= uglynumber[next])
				++next5number;
			++next;
		}
		return uglynumber[index - 1];
    }
};