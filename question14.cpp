/*
剪绳子
给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。
请问k[0]*k[1]*...*k[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度为2、3、3的三段，此时得到的乘积是18。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <vector>
#include<math.h>
using namespace::std;

int maxCutting_1(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    int* result = new int[n+1];
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;
    int max = 0;
    for(int i = 4; i <= n; ++i){
        max = 0;
        for(int j = 1; j <= i/2; ++j){
            int temp = result[j] * result[i-j];
            if(temp > max)
                max = temp;
        }
        result[i] = max;
    }
    max = result[n];
    return max;
}

int maxCutting_2(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    int num3 = n / 3;
    if(n % 3 == 1)
        num3 -= 1;
    int max = pow(3, num3) + pow(2, 2);
    return max;
}