/*
股票的最大利润
假设把某股票的价格按照时间先后顺序存储在数组中，请问买该股票一次可能获得的最大利润是多少？
例如，一直股票在某些时间节点的价格为 ｛9，11，8，5，7，12，16，14｝。
如果我们能在价格为 5 的时候买入并在价格为 16 的时候卖出，则能收获最大的利润是 11。

xiaobin9652@163.com;
Xiaobin Tian;
*/

#include<vector>
#include<math.h>
#include<iostream>
using namespace::std;

int maxdiff(vector<int> num){
    if(num.size() == 0)
        return 0;
    int min = num[0];
    int maxdiff = num[1] - min;
    for(int i = 2; i < num.size(); ++i){
        if(num[i] < min)
            min = num[i];
        else{
            if(maxdiff < num[i] - min)
                maxdiff = num[i] - min;
        }
    }
    return maxdiff;
}