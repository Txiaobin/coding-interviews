/*
输入一个整型数组，数组中有正数也有负数。数组中的一个或者连续多个整数组成一个子数组，求所有子数组的和的最大值。要求时间复杂度为 O(n)。
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
		if(array.size() == 0)
			return 0;
		vector<int> sum;
		int max = array[0];
		for(int i = 0; i < array.size(); ++i){
			int temp;
			if(i == 0 || sum[i-1] < 0)
				temp = array[i];
			if(i != 0 && sum[i-1]>0)
				temp = sum[i-1] + array[i];
			sum.push_back(temp);
			if(temp > max)
				max = temp;
		}
		return max;
    }
};