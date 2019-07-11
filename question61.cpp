/*
扑克牌中的顺子
从扑克牌中随机抽出5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2~10 为数字本身，A 为 1，J 为 11，Q 为 12，K 为 13，而大小王可以看成任意数字。
为了方便起见,可以认为大小王是0。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5)
            return false;
        sort(numbers.begin(), numbers.end());
        int NumOf0 = 0, NumOfGap = 0;
        for(int i = 0; i < numbers.size()-1; ++i){
            if(numbers[i] == 0) // 0为最小值，所以可以在一个循环中同时查找0的个数和判断间隔。
                ++NumOf0;
            else{
                if(numbers[i+1] == numbers[i])
                    return false;
                NumOfGap += numbers[i+1] - numbers[i] - 1;
            }
        }
        if(NumOfGap > NumOf0)
            return false;
        return true;
    }
};