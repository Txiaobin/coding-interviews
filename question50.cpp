/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<string>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> hashmap;
		for(int i=0; i < str.size(); ++i){
			if(hashmap.find(str[i]) == hashmap.end()){
				hashmap.insert(hashmap.end(),{str[i], 1});
			}
			else{
				hashmap[str[i]] += 1;
			}
		}
		for(int i = 0; i < str.size(); ++i){
			if(hashmap.find(str[i])->second == 1)
				return i;
		}
		return -1;
    }
};