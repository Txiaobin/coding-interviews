/*
*********************************************************************************
题目一：
翻转单词顺序
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。
例如输入 “I am a student.”, 则输出 “student. a am I”。
*********************************************************************************
题目二：
左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
定义一个函数实现字符串左旋转操作的功能。
输入 “abcdefg” 和 2，该函数返回 “cdefgab”。
*********************************************************************************

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <string>
using namespace::std;

class Solution {
public:
//题目一：翻转单词顺序
    string ReverseSentence(string str) {
        if(str.size() == 0)
            return str;
        for(int i = 0; i < str.size() / 2; ++i){
            char temp = str[i];
            str[i] = str[str.size() - 1 - i];
            str[str.size() - 1 - i] = temp;
        }
        for(int end = 0; end < str.size(); ++end){
            int begin = end;
            while(str[end] != ' ' && end < str.size())
                ++end;
            for(int i = begin; i < (begin+(end-begin)/2); ++i){
                char temp = str[i];
                str[i] = str[end - 1 - i + begin];
                str[end - 1 - i + begin] = temp;
            }
        }
        return str;
    }
//题目二：左旋转字符串
    void ReverseString(string &str, int begin, int end){ //begin和end分别为带旋转字符的收尾。
        if(begin >= end)
            return;
        for(int i = begin; i <= (begin+(end-begin)/2); ++i){
            char temp = str[i];
            str[i] = str[end -i + begin];
            str[end -i + begin] = temp;
        }
    }
    string LeftRotateString(string str, int n) {
        if(str.size() < 2)
            return str;
        ReverseString(str,0,str.size()-1);
        ReverseString(str,0,str.size()-n-1);
        ReverseString(str,str.size()-n, str.size()-1);
        return str;
    }
};