// http://www.lintcode.com/en/problem/construct-binary-tree-from-inorder-and-postorder-traversal/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    int findroot(vector<int> &inorder, int i1, int i2, int v) {
        for (int i = i1; i < i2; ++i)
            if (inorder[i] == v) return i;
        return -1;
    }
    TreeNode *build(vector<int> &inorder, int i1, int i2, vector<int> &postorder, int p1, int p2) {
        if (p1 >= p2 || i1 >= i2)
            return NULL;
        int v = postorder[p2-1];
        int i = findroot(inorder, i1, i2, v);
        TreeNode *root = new TreeNode(v);
        root->left = build(inorder, i1, i, postorder, p1, p1+i-i1);
        root->right = build(inorder, i+1, i2, postorder, p1+i-i1, p2-1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int i1 = 0, i2 = inorder.size();
        int p1 = 0, p2 = postorder.size();
        return build(inorder, i1, i2, postorder, p1, p2);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
