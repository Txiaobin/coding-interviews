/*
礼物的最大价值
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或者向下移动一格，知道到达棋盘的右下角。
给定一个棋盘以及上面的礼物，请计算你最多能拿到多少价值的礼物？

xiaobin9652@163.com;
Xiaobin Tian;
*/

#include<vector>
using namespace::std;

int getMaxVal(vector<vector<int>> val){
    if(val.size() <= 0 || val[0].size() <= 0)
        return 0;
    int *maxval = new int[val[0].size()];
    int row = val.size(), col = val[0].size();
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            int left = 0, up = 0;
            if(i > 0)
                up = maxval[j];
            if(j > 0)
                left = maxval[j-1];
            maxval[j] = max(up, left) + val[i][j];
        }
    }
    int max = maxval[col-1];
    delete[] maxval;
    return max;
}