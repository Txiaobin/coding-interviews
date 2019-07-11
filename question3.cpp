/*
数组中重复的数字
在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为 7 的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字 2 或者 3。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <unordered_set>
using namespace::std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
//解法一：哈希表的查找。
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length == 0)
            return false;
        unordered_set<int> myset;
        for(int i = 0; i < length; ++i){
            if(myset.find(numbers[i]) == myset.end())
                myset.insert(numbers[i]);
            else{
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }

//解法二：如果数字 i 不再第 i 个位置，将其放置到位置 i 。若第 i 个位置已经是数字 i ，则 i 重复。
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length == 0)
            return false;
        for(int i = 0; i < length; ++i){
            while(numbers[i] != i){                     //交换到第 i 个位置的数字依旧不是正确的位置，继续交换。
                if(numbers[ numbers[i] ] == numbers[i]){
                    *duplication = numbers[i];
                    return true;
                }
                auto temp = numbers[i];
                numbers[i] = numbers[ temp ];
                numbers[ temp ] = temp;
            }
        }
        return false;
    }
};