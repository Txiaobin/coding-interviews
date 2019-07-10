/*
*********************************************************************************
题目一：
和为 s 的两个数字。
输入一个递增排序的数组和一个数字 s，在数组中查找两个数，是的它们的和正好是 s。
如果有多对数字的和等于 s，则输出任意一对即可。
*********************************************************************************
题目二：
和为 s 的连续正数序列。
输入一个正数 s，打印出所有和为 s 的连续正数序列（至少含有两个数）。
例如，输入15，打印出 1~5，4~6，7~8。
*********************************************************************************

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <vector>
#include <unordered_map>
using namespace::std;

class Solution {
public:
//题目一：和为 s 的两个数字。
    vector<int> FindNumbersWithSum(vector<int> nums, int target){
        unordered_map<int, int> hashmap;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
            hashmap.insert({nums[i], i});
        for(int j = 0; j < nums.size(); ++j){
            int temp = target - nums[j];
            if(hashmap.find(temp) != hashmap.end() && hashmap.find(temp)->second != j){
                result.push_back(nums[j]);
                result.push_back(temp);
                return result;
            }
        }  
    }

//题目二：和为 s 的连续正数序列。
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector< vector<int> > result;
        if(sum < 3)
            return result;
        int small = 1, big = 2;
        int cursum = small + big;
        while(small < (1+sum)/2){
            if(cursum == sum){
                vector<int> temp;
                for(int i = small; i <= big; ++i){
                    temp.push_back(i);
                }
                result.push_back(temp);
                ++big;
                cursum +=big;
            }
            else if (cursum > sum){
                cursum -= small;
                ++small;
            }
            else{
                ++big;
                cursum += big;
            }
        }
        return result;
    }
};