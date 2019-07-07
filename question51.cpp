/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;

class Solution {
	int sum = 0;
	void merge(vector<int> &data, int first, int second, int length){
		vector<int> temp1, temp2;
		for(int i = first; i < first+length; ++i)
			temp1.push_back(data[i]);
		if(second + length <= data.size()){
			for(int i = second; i < second+length; ++i)
				temp2.push_back(data[i]);
		}
		else{
			for(int i = second; i < data.size(); ++i)
				temp2.push_back(data[i]);
		}
		int p1 = temp1.size() - 1, p2 = temp2.size() - 1, p3 = second + length -1;
		while(p1 >= 0 && p2 >=0){
			if(temp1[p1] > temp2[p2]){
				data[p3--] = temp1[p1--];
				sum = sum + p2 + 1;
			}
			if(temp1[p1] < temp2[p2])
				data[p3--] = temp2[p2--];
		}
		while(p1 >= 0)
			data[p3--] = temp1[p1--];
		while(p2 >= 0)
			data[p3--] = temp2[p2--];
	}
public:
    int InversePairs(vector<int> data) {
		if(data.size() == 0)
			return 0;
		for(int length = 1; length < data.size(); length<<=1){
			auto first = 0;
			auto second = first + length;
			while(second < data.size()){
				merge(data, first, second, length);
				first = second + length;
				second = first + length;
			}
		}
		return sum;
    }
};