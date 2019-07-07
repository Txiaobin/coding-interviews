/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<stack>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		unordered_map<int, int> hashmap;
		for(int i = 0; i < numbers.size(); ++i){
			if(hashmap.find(numbers[i]) == hashmap.end()){
				hashmap.insert({numbers[i], 1});
			}
			else{
				hashmap[numbers[i]] += 1;
			}
		}
		int length = numbers.size() / 2;
		int num = 0;
		for(auto it = hashmap.begin(); it != hashmap.end(); ++it){
			if(it->second > length)
				num = it->first;
		}
		return num;
    }
};