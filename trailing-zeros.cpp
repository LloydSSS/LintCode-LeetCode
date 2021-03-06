// http://www.lintcode.com/en/problem/trailing-zeros/
// https://leetcode.com/problems/factorial-trailing-zeroes/
// a.寻找5的因数的个数
// b.转化成字符串然后后项遍历

#include "lc.h"

class Solution {
 public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        if (n < 5) return 0;
        long long ans = 0;
        for (long long i = 5; i <= n; i*=5) {
        	ans += n/i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.trailingZeros(105) << endl;
	return 0;
}
