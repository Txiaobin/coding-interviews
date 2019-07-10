/*
*********************************************************************************
题目一：
数组中只出现一次的两个数字。
一个整型数组里除了两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是 O(n),空间复杂度是 O(1)。
*********************************************************************************
题目二：
数组中只出现一次的一个数字。
一个整型数组里除了一个数字之外，其他数字都出现了三次。请写程序找出这一个只出现一次的数字。
要求时间复杂度是 O(n),空间复杂度是 O(1)。
*********************************************************************************

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <vector>
#include <stdexcept>
using namespace::std;

class Solution {
    bool isBit1(int num, int index){
        num = num >> index;
        return (num & 1);
    }

public:
//题目一：数组中只出现一次的两个数字。
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2){
            return ;
        }
        int temp = 0;
        for(int i = 0; i < data.size(); ++i)
            temp ^=data[i];

        int indexBit = 0;
        if(((temp & 1) == 0) && (indexBit < 8 * sizeof(int))){
            temp = temp >> 1;
            ++indexBit;
        }

        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); ++i){
            if(isBit1(data[i], indexBit) == 1)
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
//题目二：数组中只出现一次的一个数字。
    int FindNumsAppearOnce(vector<int>data) {
        if(data.size() == 0)
            throw runtime_error("input is error");
        int x = 0, y = 0;
        for(int i = 0; i < data.size(); ++i){
            x = (x ^ data[i]) & ~y;
            y = (y ^ data[i]) & ~x;
        }
        return x;
    }
};