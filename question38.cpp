/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串 abc,则打印出由字符 a,b,c 所能排列出来的所有字符串 abc,acb,bac,bca,cab 和 cba。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace::std;

class Solution {
	vector<string> Permutationsubstring(string str, int end){
		vector<string> result;
		unordered_set<char> set;
		if(end == 1){
			string a = {str[end-1]};
			result.push_back(a);
			return result;
		}
		for(int i = end-1; i >= 0; --i){
			if(i != end-1 && set.find(str[i]) != set.end())
				continue;
			set.insert(str[i]);
			auto temp = str[end-1];
			str[end-1] = str[i];
			str[i] = temp;
			auto temp_result = Permutationsubstring(str, end-1);
			for(int j = 0; j < temp_result.size(); ++j){
				temp_result[j] = temp_result[j] + str[end-1];
				result.push_back(temp_result[j]);
			}
			temp = str[end-1];
			str[end-1] = str[i];
			str[i] = temp;
		}
		return result;
	}
public:
    vector<string> Permutation(string str) {
		vector<string> result;
        if(str.length() == 0)
			return result;
		result = Permutationsubstring(str, str.length());
        sort(result.begin(), result.end());
		return result;
    }
};