/**
 * Subsets II
 * http://oj.leetcode.com/problems/subsets-ii/
 * Prob:
 *      Given a collection of integers that might contain duplicates, S, 
 *      return all possible subsets.
 * Solution:
 *      Backtracking
 */
class Solution {
public:
    void DFS(const vector<int> &S, int idx, 
        vector<int> &tmp, vector<vector<int> > &res)
    {
        if (idx == S.size())
        {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(S[idx]);
        DFS(S, idx + 1, tmp, res);
        tmp.pop_back();
        idx ++;
        while (idx < S.size() && S[idx-1] == S[idx])
            idx ++;
        DFS(S, idx, tmp, res);
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        for (int i = 0; i < S.size()-1; i++)
            for (int j = i + 1; j < S.size(); j++)
                if (S[i] > S[j])
                {
                    int tm = S[i];
                    S[i] = S[j];
                    S[j] = tm;
                }
        vector<vector<int> > res;
        vector<int> tmp;
        DFS(S, 0, tmp, res);
        return res;
    }
};