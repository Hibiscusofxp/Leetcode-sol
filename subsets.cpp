
/**
 * 
 * http://oj.leetcode.com/problems/
 * Prob:
 *  
 * Solution:
 *  
 * CAUTION:
 *      1 << n  - 1  equals  1 << (n-1) !!!
 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        int num = (1 << n) - 1;
        // CAUTION!!
        vector <vector <int> > res;
        sort(S.begin(), S.end());
        while (num >= 0)
        {
            int tmp = num;
            vector <int> tmpVec;
            for (int i = 0; (i < n) && (tmp > 0); i++)
            {
                if (tmp & 1 == 1)
                    tmpVec.push_back(S[i]);
                tmp = tmp >> 1;
            }
            res.push_back(tmpVec);
            num --;
        }
        return res;
    }
};