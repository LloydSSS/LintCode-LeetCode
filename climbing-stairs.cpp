// http://www.lintcode.com/en/problem/climbing-stairs/
// https://leetcode.com/problems/climbing-stairs/
// 斐波那契数列，dp

#include "lc.h"

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        vector<int> dp(3);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3];
        return dp[n%3];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
