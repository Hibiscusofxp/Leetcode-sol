@@@
/**
 * Symmetric Tree
 *      http://oj.leetcode.com/problems/symmetric-tree/
 * Prob:
 * Solution:
 *      traversal INVERSELY from end to start
 * CAUTION:
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
    bool IsSubTreeSym(TreeNode* t1, TreeNode* t2)
    {
        if ( t1 == NULL && t2 == NULL )
            return true;
        if ( t1 == NULL || t2 == NULL )
            return false;
        if ( t1->val != t2->val )
            return false;
        return IsSubTreeSym(t1->left, t2->right) && IsSubTreeSym(t1->right, t2->left) ;
    }
    bool isSymmetric(TreeNode *root) {
        if (NULL == root)
            return true;
        return IsSubTreeSym(root->left, root->right);
    }
};