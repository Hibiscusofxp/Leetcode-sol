/**
 * Construct Binary Tree from Preorder and Inorder Traversal
 * http://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Prob:
 *      Given preorder and inorder traversal of a tree, construct the binary tree.
 * Solution:
 *      Recursive. pick first in preorder. use this node to split inroder traversal
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
    TreeNode* DFSBuild(vector<int> &preorder, vector<int> &inorder, int prel, int prer, int inl, int inr)
    {
        if (prel > prer)
            return NULL;
        TreeNode* cur = new TreeNode(preorder[prel]);
        int idx = inl;
        int preidx = prel+1;
        while (inorder[idx] != preorder[prel])
        {
            idx ++;
            preidx ++;
        }
        cur->left = DFSBuild(preorder, inorder, prel + 1, preidx - 1, inl, idx - 1);
        cur->right = DFSBuild(preorder, inorder, preidx, prer, idx + 1, inr);
        return cur;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return DFSBuild(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};