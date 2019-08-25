/*
替换空格
请实现一个函数，把字符串中的每个空格替换成 "%20"。
例如，输入 "We are happy.", 则输出 "We%20are%20happy."。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <string>
using namespace::std;

void replaceBlank(string &str){
    if(str.size() == 0)
        return ;
    int num = 0,length = str.size();
    for(int i = 0; i < length; ++i){
        if(str[i] == ' '){
            ++num;
            str.push_back(' ');
            str.push_back(' ');
        }
    }
    for(int i = length-1; i >= 0; --i){
        if(str[i] != ' '){
            str[i+num*2] = str[i];
        }
        else{
            str[i+num*2] = '0';
            str[i+num*2-1] = '2';
            str[i+num*2-2] = '%';
            --num;
        }
    }
}
