/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字.
例如，如果输入如下4 X 4矩阵： 1  2  3  4 
                            5  6  7  8 
                            9  10 11 12 
                            13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include<vector>
using namespace::std;


class Solution {
	vector<int> printMatrixCircle(vector<vector<int> > matrix, int start){
		vector<int> result;
		int endX = matrix[0].size() - start;
		int endY = matrix.size() - start;
		for(int i = start; i < endX; ++i)
			result.push_back(matrix[start][i]);

		if((endY - start) > 1){
			for(int i = start+1; i < endY; ++i)
				result.push_back(matrix[i][endX - 1]);

		if(((endY - start) > 1) && (endX - start) > 1)
			for(int i = endX-2; i >= start; --i)
				result.push_back(matrix[endY-1][i]);

		if(((endY - start) > 2) && (endX - start) > 1)
			for(int i = endY-2; i > start; --i)
				result.push_back(matrix[i][start]);
		}
		return result;
	}

public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		if(matrix.size() == 0)
			return result;
		int start = 0;
		while(matrix.size() > start*2 && matrix[0].size() > start*2){
			auto list = printMatrixCircle(matrix, start);
			++start;
			for(int i = 0; i < list.size(); ++i){
				result.push_back(list[i]);
			}
		}
		return result;
    }
};