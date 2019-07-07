/*
现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。

xiaobin9652@163.com;
Xiaobin Tian;
 */

class Solution {
public:
    int Fibonacci(int n) {
        int seq2 = 0, seq1 = 1;
		if(n==0 || n==1)
			return n;
		int seq;
		for(int i = 2; i <= n; ++i){
			seq = seq1 + seq2;
			seq2 = seq1;
			seq1 = seq;
		}
		return seq;
    }
};