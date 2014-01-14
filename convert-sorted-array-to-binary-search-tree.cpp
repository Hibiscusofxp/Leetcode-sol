/**
 * Convert Sorted Array to Binary Search Tree
 * http://oj.leetcode.com/problems/cs/
 * Prob:
 *      Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * Solution:
 *      Pick the middle node as the root for each subtree
 * CAUTION:
 *      check NULL of hash table index
 */
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode *sortedArrayToBSTHelper(vector<int> &num, int st, int ed)
    {
        if (st > ed)
            return NULL;
        int mid = (st + ed) >> 1;
        TreeNode *newroot = new TreeNode(num[mid]);
        newroot->left = sortedArrayToBSTHelper(num, st, mid - 1);
        newroot->right = sortedArrayToBSTHelper(num, mid + 1, ed);
        return newroot;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBSTHelper(num, 0, num.size()-1);
    }
};