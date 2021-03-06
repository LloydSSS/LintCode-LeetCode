// http://www.lintcode.com/en/problem/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 1.寻找根节点的位置，2.对左右子树递归调用

#include "lc.h"

class Solution {
public:
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int pi, int ii, int l) {
        if (l == 0)
            return nullptr;
        int rtval = preorder[pi];
        TreeNode *rt = new TreeNode(rtval);
        int pos = ii;
        while (pos < ii+l && inorder[pos] != rtval)
            pos++;
        int left_l = pos-ii;
        int right_l = l+ii-pos-1;
        rt->left = buildTreeHelper(preorder, inorder, pi+1, ii, left_l);
        rt->right = buildTreeHelper(preorder, inorder, pi+left_l+1, pos+1, right_l);
        return rt;

    }
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return nullptr;
        return buildTreeHelper(preorder, inorder, 0, 0, preorder.size());
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
