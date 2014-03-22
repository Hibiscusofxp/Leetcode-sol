
/**
 * 
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
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector< vector <int> > result;
        Queue< TreeNode* > q;
        vector<int> curLevelVal;
        if (root == NULL)
            return result;
        int curLevel = 1;
        int nextLevel = 0;
        q.push(root);xz
        while (! q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            curLevelVal.push_back(cur->val);
            if (cur->left != NULL)
            {
                q.push(cur->left);
                nextLevel ++;
            };
            if (cur->right != NULL)
            {
                q.push(cur->right);
                nextLevel ++;
            };
            curLevel --;
            if (curLevel == 0)
            // do not write if (curLevel == 0); = =!!
            {
                curLevel = nextLevel;
                nextLevel = 0;
                if (!leftToRight)
                    reverse(curLevelVal.begin(), curLevelVal.end());
                result.push_back(curLevelVal);
                curLevelVal.clear();
                leftToRight = !leftToRight;
            }
        }
        // std::reverse(result.begin(), result.end());
        return result;
    }
};