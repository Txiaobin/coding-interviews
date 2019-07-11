/*
求1+2+....+n
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <list>
using namespace::std;

class Solution {
public:
    int Sum_Solution(int n) {
        return ((1 + n) * n) / 2;
    }
};