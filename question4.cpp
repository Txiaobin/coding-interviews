/*
二维数组的查找
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上往下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该数。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <vector>
using namespace::std;

bool Find(vector<vector<int>> matrix, int number){
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int i = 0,j = matrix[0].size();
    while(i > 0 && j <matrix.size()){
        if(matrix[i][j] == number)
            return true;
        else if(matrix[i][j] < number)
            ++j;
        else
            --i;
    }
    return false;
}