/*
最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
假设字符串中只包含 ‘a’-‘z’ 的字符。
例如在字符串 “arabcacfr” 中，最长的不包含字符的子字符串是 “acfr”，长度为4。

xiaobin9652@163.com;
Xiaobin Tian;
*/

#include<string>
using namespace::std;

int longestSubstring(string str){
    int curlength = 0, maxlength = 0;
    int *position = new int[26];
    for(int i = 0; i < 26; ++i)
        position[i] = -1;
    for(int i = 0; i < str.size(); ++i){
        int preIndex = position[str[i] - '0'];
        if(preIndex < 0 || i - preIndex > curlength)
            ++curlength;
        else{
            if(curlength > maxlength)
                maxlength = curlength;
            curlength = i - preIndex;
        }
        position[str[i] - '0'] = i;
    }
    if(curlength > maxlength)
        maxlength = curlength;
    delete[] position;
    return maxlength;
}