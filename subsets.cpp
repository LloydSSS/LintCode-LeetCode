// http://www.lintcode.com/en/problem/subsets/
// https://leetcode.com/problems/subsets/
// 先排序，以便去重
// 递归，每个元素都有两种状态，取或者不取
// 非递归，构造法，先构造0个元素的，再在这个基础上构造有第一个元素的subset，以此类推

#include "lc.h"

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> ss;
    //  dfs(ss, 0, nums);
        ans.push_back(vector<int>());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = ans.size()-1; j >= 0; --j) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
    vector<vector<int> > ans;
    void dfs(vector<int> ss, int i, vector<int> &nums) {
        ans.push_back(ss);
        for (int j = i; j < nums.size(); ++j) {
            if (j != i && nums[j] == nums[j-1])
                continue;
            ss.push_back(nums[j]);
            dfs(ss, j+1, nums);
            ss.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
