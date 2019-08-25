/*
把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译成字符串。
0 翻译成 “a”， 1 翻译成 “b”，....， 25 翻译成 “z”。一个数字可能有多个翻译。
例如， 12258 有 5 中不同的翻译，分别是 “bccfi”、“bwfi”、“bczi”、“mcfi”、“mzi”。
请编程实现一个函数，用来计算一个数字有多少种翻译方法。

xiaobin9652@163.com;
Xiaobin Tian;
*/

#include<vector>
using namespace::std;

int GetTranslationCout(int number){
    if(number < 0)
        return 0;
    if(number < 10)
        return 1;
    vector<int> num;
    num.push_back(0);
    while(number != 0){
        num.push_back(number%10);
        number = number / 10;
    }
    int *cout = new int[num.size()];
    cout[0] = 1;
    cout[1] = 1;
    for(int i = 2; i < num.size(); ++i){
        int temp = num[i] * 10 + num[i-1];
        if(temp <= 25 && temp >= 10){
            cout[i] = cout[i-1] + cout[i-2];           
        }
        else{
            cout[i] = cout[i-1];
        }
    }
    int result = cout[num.size()-1];
    delete[] cout;
    return result;
}