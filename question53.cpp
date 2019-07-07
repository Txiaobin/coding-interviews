/*
统计一个数字在排序数组中出现的次数。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;

class Solution {
	int GetFirstK(vector<int> data, int k){
		int begin = 0, end = data.size() - 1;
		while(begin  <= end){
			int mid = (begin + end) / 2;
			if(data[mid] < k)
				begin = mid + 1;
			else if(data[mid] > k)
				end = mid - 1;
			else{
				if(data[mid-1] != k)
					return mid;
				end = mid - 1;
			}
		}
		return -1;
	}

	int GetEndK(vector<int> data, int k){
		int begin = 0, end = data.size() - 1;
		while(begin  <= end){
			int mid = (begin + end) / 2;
			if(data[mid] < k)
				begin = mid + 1;
			else if(data[mid] > k)
				end = mid - 1;
			else{
				if(data[mid+1] != k)
					return mid;
				begin = mid + 1;
			}
		}
		return -1;
	}
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0)
			return 0;
		auto first = GetFirstK(data, k);
		auto end = GetEndK(data, k);
		if(first == -1)
			return 0;
		return end - first + 1;
    }
};