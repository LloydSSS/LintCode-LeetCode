// http://www.lintcode.com/en/problem/copy-books/#
// dp[i][j] 表示前j个人抄写前i本书的最小时间。
// dp[i][j] = min(dp[i][j], max(dp[t][j-1], sum[i] - sum[t]));
// global[i][j] = min(global[i][j-1], local[i][j]);
// local[i][j] = min(local[t][j-1]+sum[t+1~i]);

#include "lc.h"

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        int ans = 0;
        if (k >= n) {
            for (int i = 0; i < n; ++i)
                ans = max(ans, pages[i]);
            return ans;
        }

        vector<vector<int> > dp(n+1, vector<int>(k+1, INT_MAX));
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + pages[i-1];
            dp[i][1] = sum[i];
        }

        for (int j = 2; j <= k; ++j) {
            for (int i = j; i <= n; ++i) {
                for (int l = j-1; l < i; ++l)
                    dp[i][j] = min(dp[i][j], max(dp[l][j-1], sum[i]-sum[l]));
            }
        }

        return dp[n][k];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
