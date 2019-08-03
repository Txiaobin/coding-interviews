/*
表示数值的字符串
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串 "+100","5e2","-123","3.1416" 和 "-1E-16" 都表示数值。
但是 "12e","1a3.14","1.2.3","+-5" 和 "12e+4.3" 都不是。

xiaobin9652@163.com;
Xiaobin Tian;
 */


class Solution {
    bool scanInteger(char **str){
        if(**str == '+' || **str == '-')
            ++(*str);
        return scanUnsignedInteger(str);
    }

    bool scanUnsignedInteger(char **str){
        auto p = *str;
        while(**str != '\0' && (**str >= '0' && **str <= '9')){
            ++(*str);
        }
        return *str > p;
    }
public:
    bool isNumeric(char* str){
        if(str == nullptr)
            return false;
        auto p = str;
        bool flag = scanInteger(&p);
        if(*p == '.'){
            ++p;
            flag = scanUnsignedInteger(&p) || flag;
        }
        if(*p == 'e' || *p == 'E'){
            ++p;
            flag = flag && scanInteger(&p);
        }
        return flag && (*p == '\0');
    }
};