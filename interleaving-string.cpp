#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1));
        dp[0][0] = true;
        for (int i = 1; i <= s1.size() && s1[i-1] == s3[i-1]; ++i) {
                dp[i][0] = true;
        }
        for (int i = 1; i <= s2.size() && s2[i-1] == s3[i-1]; ++i) {
                dp[0][i] = true;
        }

        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                } else if (dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
