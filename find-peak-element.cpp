// http://www.lintcode.com/en/problem/find-peak-element/
// https://leetcode.com/problems/find-peak-element/
// 二分查找，[)

#include "lc.h"

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int l = 0, r = A.size();
        while (l < r) {
            int m = (l+r) >> 1;

            if (A[m-1] < A[m] && A[m] > A[m+1]) return m;

            if (A[m-1] < A[m])
                l = m;
            else
                r = m;
        }
        return l;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {100,102,104,7,9,11,4,3};
    cout << sol.findPeak(v) << endl;
	return 0;
}
