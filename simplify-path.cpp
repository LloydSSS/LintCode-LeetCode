// http://www.lintcode.com/en/problem/simplify-path/
// https://leetcode.com/problems/simplify-path/
// stack

#include "lc.h"

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        stack<string> st;
        string ans;
        int i = 1, j = 0;
        while (i < path.size() && j != -1) {
            j = path.find_first_of("/", i);
            string cur;
            if (j == -1) {
                cur = path.substr(i);
            } else {
                cur = path.substr(i, j-i);
            }
            i = j+1;
            if (cur == "..") {
                if (!st.empty()) st.pop();
            } else if (cur != "." && cur != "")
                st.push(cur);
        }
        while (!st.empty()) {
            string cur = st.top();
            st.pop();
            ans = string("/") + cur + ans;
        }
        if (ans == "") ans = "/";
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    string s("/abc/...");
    cout << sol.simplifyPath(s) << endl;
    return 0;
}
