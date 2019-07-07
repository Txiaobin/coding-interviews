/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为 321323。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<string>
using namespace::std;

class Solution {
	bool mycompare(string str1, string str2){
		auto copystr1 = str1 + str2;
		auto copystr2 = str2 + str1;
		if(copystr1 < copystr2)
			return true;
		else
			return false;
	}
	void strsort(vector<string> &str,int begin, int end){
		if(begin>=end)
        	return ;
    	auto mark = str[begin];
    	int i = begin, j = end;
   	 	while(i < j){
        	while(i != j && mycompare(mark, str[j])){
            	--j;
        	}
        	if(i != j){
            	str[i] = str[j];
            	++i;
       	 	}
        	while(i != j && mycompare(str[i], mark)){
            	++i;
        	}
        	if(i != j){
            	str[j] = str[i];
            	--j;
        	}
    	}
    	str[i] = mark;
    	strsort(str, begin, i-1);
    	strsort(str, i+1, end);
	}
public:
    string PrintMinNumber(vector<int> numbers) {
		vector<string> str;
		string result;
		for(int i=0; i < numbers.size(); ++i){
			str.push_back(to_string(numbers[i]));
		}
        strsort(str, 0, numbers.size()-1);
		for(int i=0; i < str.size(); ++i){
			result = result + str[i];
		}
		return result;
    }
};