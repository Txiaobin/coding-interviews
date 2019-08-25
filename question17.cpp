/*
打印从1到最大的 n 位数。
输入数字 n，按照顺序打印出 1 到最大的 n 位十进制数。
比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <iostream>
#include<string.h>
using namespace::std;

void printnumber(char* number){
    bool isBegin = true;
    char *p = number;
    while(*p != '\0'){
        if(isBegin == true && *p != '0')
            isBegin == false;
        if(isBegin == true)
            cout<<*p;
    }
    cout<<endl;
}

bool Increase(char* number, int n){
    int flag = 0;
    for(int i = n-1; i >= 0; ++i){
        int num = number[i] - '0' + flag;
        if(i == n-1)
            ++num;
        if(num > 9){
            if(i == 0)
                return false;
            else{
                num = num - 10;
                flag = 1;
                number[i] = '0' + num;
            }
        }
        else{
            number[i] = '0' + num;
            break;
        }
    }
    return true;
}

void print1ton_1(int n){
    if(n < 1)
        return;
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    while(!Increase(number, n)){
        printnumber(number);
    }
    delete[] number;
}

void Print(char *number, int n, int index){
    if(index == n){
        printnumber(number);
        return;
    }
    for(int i = 0; i < 10; ++i){
        number[index] = '0' + i;
        Print(number, n, index+1);
    }
}

void print1ton_2(int n){
    if(n < 1)
        return;
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    for(int i = 0; i < 10; ++i){
        number[0] = '0' + i;
        Print(number, n, 1)
    }
    delete[] number;
}