// http://www.lintcode.com/en/problem/heapify/
// 堆操作

#include "lc.h"

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = 1; i < A.size(); ++i)
            siftup(A, i);
    }

    void siftup(vector<int> &heap, int start) {
        int j = start, i=(j-1)/2;
        while(j > 0) {
            if(heap[i] <= heap[j])
                break;
            else {
                //向上调整工作
                swap(heap[i], heap[j]);
                j = i;
                i = (i-1)/2;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
