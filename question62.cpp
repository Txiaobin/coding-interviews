/*
圆圈中最后剩下的数字
0，1，....，n-1 这 n 个数字排成一个圆圈，从数字 0 开始，每次从这个圆圈中删除第 m 个数字。
求出这个圆圈里剩下的最后一个数字。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <list>
using namespace::std;

class Solution {
public:
//解法一：模拟圆圈进行删除。
    int LastRemaining_Solution(int n, int m){
        if(n < 1 || m <1)
            return -1;
        list<int> mylist;
        for(int i=0; i < n; ++n)
            mylist.push_back(i);
        auto it = mylist.begin();
        while(mylist.size() > 1){
            for(int i = 1; i < m; ++i){
                ++ it;
                if(it == mylist.end())
                    it = mylist.begin();
            }
            auto temp = it++;
            if(it == mylist.end())
                it = mylist.begin();
            mylist.erase(temp);
        }
        return mylist.front();
    }
//解法二：找规律。
//f(n,m)={0, n=1; [f(n-1,m)+m]%n, n>1}。
    int LastRemaining_Solution(int n, int m){
        if(n < 1 || m <1)
            return -1;
        int f = 0;
        for(int i = 2; i <= n; ++i){
            f = (f + m) % i;
        }
        return f;
    }
};