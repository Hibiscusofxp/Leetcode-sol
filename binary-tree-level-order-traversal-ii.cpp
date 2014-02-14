
/**
 * binary-tree-level-order-traversal-ii
 * http://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii
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

 #include <algorithm> //reverse

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

template <class T>
class Queue {
    T *q;
    int cap, idx, head;
public:
    // template <class T>
    Queue (const int size = 200000): cap(size), idx(0), head(0)
    {
        q = new T[size];
    }

    // template <class T>
    bool empty()
    {
        return (idx == head);
    }

    // template <class T>
    bool full()
    {
        return (idx == cap);
    }

    // template <class T>
    void push (const T& val)
    {
        if (full())
            return;
        q[idx ++] = val;
    }

    // template <class T>
    void pop()
    {
        if (empty())
            return;
        head ++;
    }

    T front()
    {
        if (empty())
            return NULL;
        return q[head];
    }
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector< vector <int> > result;
        Queue< TreeNode* > q;
        vector<int> curLevelVal;
        if (root == NULL)
            return result;
        int curLevel = 1;
        int nextLevel = 0;
        q.push(root);
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
                result.push_back(curLevelVal);
                curLevelVal.clear();
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};