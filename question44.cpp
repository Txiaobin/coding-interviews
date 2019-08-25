/*
数字序列中某一位的数字
数字以 0123456789101112131415...的格式序列化到一个字符序列中。在这个序列中，第5位是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <iostream>
#include<math.h>
using namespace::std;

int coutOfDigits(int digits){
    if(digits == 1)
        return 10;
    int cout = (int)pow(10,digits-1);
    return 9*cout;
}

int beginDigits(int digits){
    if(digits == 1)
        return 0;
    return (int)pow(10,digits-1);
}

int digitAtIndex(int index, int digits){
    int numbers = beginDigits(digits) + index/digits;
    int indexfromright = digits - index % digits;
    for(int i = 1; i < indexfromright; ++i){
        numbers = numbers / 10;
    }
    return numbers % 10;
}

int digitAtIndex(int index){
    if(index < 0)
        return -1;
    int digits = 1;
    while(true){
        int numbers = coutOfDigits(digits);
        if(numbers * digits > index){
            return digitAtIndex(index, digits);
        }
        index -= (numbers * digits);
        ++digits;
    }
    return -1;
}