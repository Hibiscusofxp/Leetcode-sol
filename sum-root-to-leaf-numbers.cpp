/**
 * Sum Root to Leaf Numbers 
 * http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 * Prob:
 *      each root-to-leaf path could represent a number
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
    // assume node != NULL
    void DFS(TreeNode* node, int curVal, int &sum)
    {
        if (node->left == NULL && node->right == NULL)
        {
            sum += curVal * 10 + node->val;
            return;
        }
        if (node->left != NULL)
            DFS(node->left, curVal * 10 + node->val, sum);
        if (node->right != NULL)
            DFS(node->right, curVal * 10 + node->val, sum);
    }
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }
};
