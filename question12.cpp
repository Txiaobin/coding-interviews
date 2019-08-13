/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e 
     s f c s 
     a d e e 
这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

xiaobin9652@163.com;
Xiaobin Tian;
 */


class Solution {
public:
    bool hasPathCore(char* matrix, int rows, int i, int cols, int j, char* str, int &pathlength, bool *visited){
        if(str[pathlength] == '\0')
            return true;
        bool hasPath = false;
        if(i>=0 && i<rows && j>=0 && j<cols && matrix[i*cols+j] == str[pathlength] && visited[i*cols+j]!=true){
            ++pathlength;
            visited[i*cols+j] = true;
            hasPath = hasPathCore(matrix, rows, i, cols, j-1, str, pathlength, visited)
                    ||hasPathCore(matrix, rows, i-1, cols, j, str, pathlength, visited)
                    ||hasPathCore(matrix, rows, i, cols, j+1, str, pathlength, visited)
                    ||hasPathCore(matrix, rows, i+1, cols, j, str, pathlength, visited);
            if(hasPath == false){
                --pathlength;
                visited[i*cols+j] = false;
            }
        }
        return hasPath;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str){
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        bool *visited = new bool[rows*cols];
        for(int i = 0; i < rows*cols; ++i)
            *(visited+i) = false;
        int pathlength = 0;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(hasPathCore(matrix, rows, i, cols, j, str, pathlength, visited))
                    return true;
            }
        }
        delete visited;
        return false;
    }
};