// http://www.lintcode.com/zh-cn/problem/merge-intervals/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

// Definition of Interval:
class Interval{
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool cmp(const Interval &a, const Interval &b) {
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (cur.end < intervals[i].start) {
                ans.push_back(cur);
                cur = intervals[i];
            } else {
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        ans.push_back(cur);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}