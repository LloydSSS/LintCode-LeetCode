// http://www.lintcode.com/en/problem/reverse-linked-list-ii/
// https://leetcode.com/problems/reverse-linked-list-ii/
// 使用头插法比较简单

#include "lc.h"

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 0; i < m-1; ++i)
            pre = pre->next;
        ListNode *cur = pre->next;
        int i = m;
        while (i < n) {
            ListNode *ne = cur->next;
            cur->next = ne->next;
            ne->next = pre->next;
            pre->next = ne;
            i++;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
