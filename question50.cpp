/*
*********************************************************************************
题目一：字符串中第一个只出现一次的字符
在字符串中找到第一个只出现一次的字符。
如输入“abaccdeff”，则输出‘b’。
*********************************************************************************
题目二：字符流中第一个只出现一次的字符
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
*********************************************************************************


xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<unordered_map>
#include<unordered_set>
using namespace::std;

class Solution {
public:
//题目一：字符串中第一个只出现一次的字符
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> hashmap;
		for(int i=0; i < str.size(); ++i){
			if(hashmap.find(str[i]) == hashmap.end()){
				hashmap.insert({str[i], 1});
			}
			else{
				auto it =  hashmap.find(str[i]);
				it->second = it->second + 1;
			}
		}
		for(int i = 0; i < str.size(); ++i){
			auto it =  hashmap.find(str[i]);
			if(it->second == 1)
				return i;
		}
		return -1;
    }

//题目二：字符流中第一个只出现一次的字符
    void Insert(char ch){//Insert one char from stringstream
        if(hashmap.find(ch) != hashmap.end())
			 hashmap.erase(ch);
		else
			hashmap.insert({ch,index});
		++index; 
    }

    char FirstAppearingOnce(){//return the first appearence once char in current stringstream
		char ch;
		int mixindex = index;
		if(hashmap.size() == 0)
			return '#';
		for(auto it = hashmap.begin(); it != hashmap.end(); ++it){
			if(mixindex > it->second){
				mixindex = it->second;
				ch = it->first;
			}
		}
		return ch;
    }

private:
	unordered_map<char, int> hashmap;
	int index = 0;
};