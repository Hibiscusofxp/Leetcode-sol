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
    void DFS(int level, const vector<int> &S, vector<int> &tmp, vector< vector<int> > &res) {
        if (level == S.size()) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(S[level]);
        DFS(level + 1, S, tmp, res);
        tmp.pop_back();
        level ++;
        while (level < S.size() && S[level] == S[level - 1])
            level ++;
        DFS(level, S, tmp, res);
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        std::vector< vector <int> > res;
        std::vector<int> tmp;
        sort(S.begin(), S.end());
        DFS(0, S, tmp, res);
        return res;
    }
};