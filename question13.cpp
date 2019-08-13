/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

xiaobin9652@163.com;
Xiaobin Tian;
 */


class Solution {
public:
    int sumnum(int i){
        int sum = 0;
        while(i != 0){
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }
    bool check(int threshold, int rows, int i, int cols, int j, bool *visited){
        if(i>=0 && i<rows && j>=0 && j<cols && visited[i*cols+j] == false){
            if(sumnum(i) + sumnum(j) <= threshold)
                return true;
        }
        return false;
    }
    int movingCountCore(int threshold, int rows, int i, int cols, int j, bool *visited){
        int count = 0;
        if(check(threshold, rows, i, cols, j, visited)){
            visited[i*cols+j] = true;
            count = movingCountCore(threshold, rows, i-1, cols, j, visited)
                  + movingCountCore(threshold, rows, i, cols, j-1, visited)
                  + movingCountCore(threshold, rows, i+1, cols, j, visited)
                  + movingCountCore(threshold, rows, i, cols, j+1, visited)
                  + 1;
        }
        return count;
    }
    int movingCount(int threshold, int rows, int cols){
        if(threshold < 0 || rows < 0 || cols < 0)
            return 0;
        bool *visited = new bool[rows*cols];
        for(int i = 0; i < rows*cols; ++i)
            visited[i] = false;
        int result = movingCountCore(threshold, rows, 0, cols, 0, visited);
        delete[] visited;
        return result;
    }
};