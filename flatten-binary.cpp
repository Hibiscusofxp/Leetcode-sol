
/**
 * flatten-binary
 * http://oj.leetcode.com/problems/
 * Prob:
 *  
 * Solution:
 *  
 * CAUTION:
 *
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
    void DFSPreOrder (TreeNode * &root, TreeNode * &resHead, TreeNode * &resTail) {
        if (root == NULL) {
            resHead = NULL;
            resTail = NULL;
            return;
        }
        TreeNode *lHead, *lTail, *rHead, *rTail;
        DFSPreOrder (root->left, lHead, lTail);
        DFSPreOrder (root->right, rHead, rTail);
        root->left = NULL;
        root->right = NULL;
        resHead = root;
        resTail = root;
        if (lHead != NULL) {
            resTail->right = lHead;
            resTail = lTail;
        }
        if (rHead != NULL) {
            resTail->right = rHead;
            resTail = rTail;
        }
        return;
    }
public:
    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        TreeNode *resHead, *resTail;
        DFSPreOrder(root, resHead, resTail);
    }
};