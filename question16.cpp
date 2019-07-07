/*
给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
#include<stack>
#include<stdexcept>
using namespace::std;

class Solution {
    double power(double base, int exp) {
        if (exp == 1) return base;
        if ((exp & 1) == 0) {
            int tmp = power(base, exp >> 1);
            return tmp * tmp;
        } else {
            int tmp = power(base, (exp - 1) >> 1);
            return tmp * tmp * base;
        }
    }
public:
    double Power(double base, int exp) {
        if (base == 0) {
            if (exp > 0) return 0;
            else if (exp == 0) return 0;
            else throw invalid_argument("Invalid input!");
        } else {
            if (exp > 0) return power(base, exp);
            else if (exp == 0) return 1;
            else return 1 / power(base, -exp);
        }
    }
};