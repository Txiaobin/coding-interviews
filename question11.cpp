/*
旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 {3,4,5,1,2} 为 {1，2，3，4，5} 的一个旋转，该数组的最小元素为1。

xiaobin9652@163.com;
Xiaobin Tian;
 */

#include <vector>
#include<exception>
using namespace::std;

int min(vector<int> numbers){
    if(numbers.size() == 0)
        return -1;
    int left = 0, right = numbers.size()-1;
    int mid;
    while(numbers[left] > numbers[right]){
        if(right - left == 1){
            return numbers[right];
        }
        mid = (left + right) / 2;
        if(numbers[mid] >= numbers[left])
            left = mid;
        else if(numbers[mid] < numbers[left])
            right = mid;
    }
    return numbers[mid];
} 