/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

xiaobin9652@163.com;
Xiaobin Tian;
 */

class Solution {
public:
     int  NumberOf1(int n) {
		 int num = 0;
		 int i = 1;
		 while (i){
			if(i & n)
			 	++num;
			i = i<<1;
		 }
		 return num;
	 }
};