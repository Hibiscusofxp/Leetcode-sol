/**
 * Minimum Depth of Binary Tree 
 * http://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 * Prob:
 *      Given a binary tree, find its minimum depth
 * Solution:
 *      Backtracking. go throught the tree
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
public:
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if (left == 0 && right == 0)
            return 1;
        // careful about following two conditions
        else if (left == 0)
            return (right + 1);
        else if (right == 0)
            return (left + 1);
        else
        {
            if (left < right)
                return (left + 1);
            else
                return (right + 1);
        }
    }
};