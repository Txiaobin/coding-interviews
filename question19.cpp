/*
正则表达式匹配
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

xiaobin9652@163.com;
Xiaobin Tian;
 */

class Solution {
    bool matchcore(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(*(pattern+1) == '*'){
            if(*pattern == *str || (*pattern == '.' && *str != '\0')){
                return (matchcore(str+1, pattern+2) || matchcore(str+1, pattern) || matchcore(str, pattern+2));
                /*matchcore(str+1, pattern+2) 为 * 代替 1 个字符；
                  matchcore(str+1, pattern) 为 * 代替大于 1 个字符；
                  matchcore(str, pattern+2) 为 * 代替 0 个字符。
                */ 
            }
            else
                return matchcore(str, pattern+2);// str 和 pattern 字符不相同，即 * 代替 0 个字符。
        }
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchcore(str+1, pattern+1);
        return false;
    }
public:
    bool match(char* str, char* pattern){
        if(str == nullptr && pattern == nullptr)
            return false;
        return matchcore(str, pattern);
    }
};