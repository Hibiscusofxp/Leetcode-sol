
/**
 * binary-tree-level-order-traversal
 * http://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 * Prob:
 *      Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * Solution:
 *      iterative. traversal the tree and at the same time keep track of the depth of that node. putting the node to corresponding vector is a piece of cake
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
    void DFSTraversal(int level, TreeNode *node)
    {
        if (NULL == node)
            return;
        if (level > (int)ans.size() - 1)
            ans.push_back(vector<int>(0));
        DFSTraversal(level + 1, node->left);
        ans[level].push_back(node->val);
        DFSTraversal(level + 1, node->right);
        // pre-order, in-order, post-order all work well
        return;
    }
public:
    vector<vector<int> > ans;
    vector<vector<int> > levelOrder(TreeNode *root) {
        DFSTraversal(0, root);
        return ans;       
    }
};