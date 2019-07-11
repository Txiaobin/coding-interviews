/*
把字符串转换成整数
将一个字符串转换成一个整数的功能，要求不能使用字符串转换整数的库函数。 
string不符合数字要求时返回0，数值为0或者字符串不是一个合法的数值则返回0。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <string>
using namespace::std;

class Solution {
public:
    int StrToInt(string str) {
        if(str.size() == 0)
            return 0;
        long long num = 0;
        int flag = 1;
        if(str[0] == '-')
            flag = -1;
        for(int i = 0; i < str.size(); ++i){
            if(i == 0 && (str[i] == '+' || str[i] == '-'))
                continue;
            if(str[i] > '9' || str[i] < '0')
                return 0;
            num = num * 10 + (str[i]-'0');
        }
        return flag * num;
    }
};