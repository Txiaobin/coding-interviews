/*
n 个骰子的点数
把 n 个骰子扔在地上，左右骰子朝上一面的点数之和为 s。
输入 n，打印出 s 的所有可能的值出现的概率。

xiaobin9652@163.com;
Xiaobin Tian;
*/

#include<vector>
#include<math.h>
#include<iostream>
using namespace::std;

int max_val = 6;

void Probability(int num, int curnum, int sum, vector<int> &probability){
    if(curnum == 0)
        ++probability[sum - num];
    else{
        for(int i = 1; i < max_val; ++i){
            Probability(num, curnum-1, sum + i, probability);
        }
    }
}

void PrintProbability(int num){
    if(num < 1)
        return;
    int maxnum = num * max_val;
    vector<int> probabilty;
    for(int i = num; i <= maxnum; ++i)
        probabilty.push_back(0);
    Probability(num, num, 0, probabilty);
    int total = pow((double)max_val, num);
    for(int i = num; i <= maxnum; ++i){
        double ratio = (double)(probabilty[i-num]) / total;
        printf("%d:%e", i, ratio);
    }
} 
/*
******************************************************************
*/
void PrintProbability(int num){
    if(num < 1)
        return;
    vector< vector<int> > probability;
    vector<int> temp1, temp2;
    int flag = 0;
    for(int i = 0; i < max_val * num +1; ++i){
    
        temp1.push_back(0);
        temp2.push_back(0);
    }
    probability.push_back(temp1);
    probability.push_back(temp2);
    for(int i = 1; i <= max_val; ++i){
        probability[flag][i] = 1;
    }
    for(int k = 2; k <= num; ++k){
        for(int i = 0; i < k; ++i)
            probability[1-flag][i] = 0;
        for(int i = k; i <= max_val * num; ++i){
            probability[1-flag][i] = 0;
            for(int j = 1; j <= i && j <= max_val; ++j)
                probability[1-flag][i] += probability[flag][i-j];
        }
        flag = 1 - flag;
    }
    double total = pow((double)max_val, num);
    for(int i = 1; i <= max_val * num; ++i){
        double ratio = (double)probability[flag][i] / total;
        printf("%d:%e", i, ratio);
    }
}

