/*
数组中重复的数字
在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为 7 的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字 2 或者 3。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <vector>
using namespace::std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> C, D, B;
        C.push_back(1);
        D.push_back(1);
        for(int i = 1; i < A.size(); ++i){
            C.push_back(C[i-1] * A[i-1]);
            D.push_back(D[i-1] *A[A.size()- i]);
        }
        for(int i = 0; i < A.size(); ++i)
            B.push_back(C[i] * D[A.size() - 1 - i]);
        return B;
    }
};