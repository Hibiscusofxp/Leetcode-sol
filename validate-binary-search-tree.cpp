
/**
 * validate-binary-search-tree
 * http://oj.leetcode.com/problems/validate-binary-search-tree
 * Prob:
 *      determine if it is a valid binary search tree (BST).
 * Solution:
 *      recursive
 * CAUTION:
 *      remember to record the min and max value of current subtree
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
    bool DFSIsValid(TreeNode* node, int &min, int &max)
    {
        if (NULL == node)
            return true;
        int leftMin, leftMax, rightMin, rightMax;
        if (node->left != NULL)
        {
            if (! DFSIsValid(node->left, leftMin, leftMax) )
                return false;
            if ( leftMax >= node->val)
                return false;
        }
        else
        {
            leftMin = node->val;
            leftMax = node->val;
        };
        if (node->right != NULL)
        {
            if (! DFSIsValid(node->right, rightMin, rightMax) )
                return false;
            if ( rightMin <= node->val)
                return false;
        }
        else
        {
            rightMin = node->val;
            rightMax = node->val;
        }
        min = leftMin;
        max = rightMax;
        return true;
    }
public:
    bool isValidBST(TreeNode *root) {
        if (NULL == root)
            return true;
        int minVal;
        int maxVal;
        return DFSIsValid(root, minVal, maxVal);
    }
};