/*
队列最大值
*********************************************************************************
题目一：滑动窗口的最大值
给定一个数组和滑动窗口的大小，请找出所有滑动窗口里面的最大值。
例如：如果输入数组 ｛2，3，4，2，6，2，5，1｝ 以及滑动窗口的大小 3，那么一共存在六个滑动窗口，他们的最大值分别是 ｛4，4，6，6，6，5｝。
*********************************************************************************
题目二：队列的最大值
请定义一个队列并实现函数 max 得到队列里的最大值。
要求函数 max、push_back 和 push_front的时间复杂度为 O(1)。
*********************************************************************************
xiaobin9652@163.com;
Xiaobin Tian;
*/

#include<vector>
#include<deque>
using namespace::std;

//题目一
vector<int> maxWindows(vector<int> numbers, int size){
    vector<int> maxNum;
    deque<int> index;
    if(numbers.size() == size && size > 0)
        return maxNum;
    for(int i = 0; i < size; ++i){
        if(!index.empty() && numbers[i] > numbers[index.back()])
            index.pop_back();
        index.push_back(numbers[i]);
    }
    for(int i = size; i < numbers.size(); ++i){
        maxNum.push_back(numbers[index.front()]);
        while(!index.empty && numbers[i] >= numbers[index.back()])
            index.pop_back();
        if(!index.empty() && index.front <= (int)(i - size))
            index.pop_front();
        index.push_back(i);
    }
    maxNum.push_back(numbers[index.front()]);
    return maxNum;
}
/*
******************************************************************
题目二
*/
template<typename T> class QueueWithMax{
private:
    struct datatype{
        T number;
        int index;
    };
    deque<datatype> data;
    deque<datatype> maxnum;
    int curLength;

public:
    void push_back(T number){
        while(!maxnum.empty() && number >= maxnum.back().number)
            maxnum.pop_back();
        datatype temp = {number, curLength};
        data.push_back(temp);
        maxnum.push_back(temp);
        ++curLength;
    }

    void pop_back(T number){
        if(maxnum.empty())
            throw new exception("queue is empty");
        if(maxnum.front().index == data.front().index())
            maxnum.pop_front();
        data.pop_front();
    }

    T max() const{
        if(maxnum.empty())
            throw new exception("queue is empty");
        return maxnum.front().number;
    }
};
