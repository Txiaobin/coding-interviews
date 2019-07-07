/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() == 0)
			return;
		for(int i =1; i< array.size(); ++i){
			if((array[i] & 1) == true){
				int j = i-1;
				while(j >= 0 && (array[j] & 1) == false){
					int temp = array[j+1];
					array[j+1] = array[j];
					array[j] = temp;
					--j;
				}
			}
		}
    }
};