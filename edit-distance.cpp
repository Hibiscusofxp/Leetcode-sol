@@@
/**
 * Edit Distance
 * http://oj.leetcode.com/problems/edit-distance/
 * Prob:
 *      Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
 *      in each step you can insert, delete or replace a character
 * Solution:
 *      So neat!! DP
 *      let f[i][j] be the minimum operations for first i chars of word1(CAUTION: is 0..i-1) and j chars of word2 to be the same
 *          f[i][j] = min { min (f[i-1][j], f[i][j-1]) + 1,
 *                      f[i-1][j-1] (if w1[i-1] == w2[j-1]) or 
 *                      f[i-1][j-1] + 1 (if w1[i-1] != w2[j-1]) }
 *          f[0][0] = 0;
 *          f[0][k] = k;
 *          f[k][0] = k; 
 * CAUTION:
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1 == "" && word2 == "")
            return 0;
        vector< vector<int> > f(word1.length() + 1, vector<int> (word2.length()+1 ));
        f[0][0] = 0;
        for (int i = 0; i <= word1.length(); i++)
            f[i][0] = i;
        for (int i = 0; i <= word2.length(); i++)
            f[0][i] = i;
        for (int i = 1; i <= word1.length(); i++)
            for (int j = 1; j <= word2.length(); j++)
            {
                f[i][j] = min (f[i-1][j] + 1, f[i][j-1] + 1);
                if (word1[i-1] == word2[j-1])
                    f[i][j] = min (f[i][j], f[i-1][j-1]);
                else
                    f[i][j] = min (f[i][j], f[i-1][j-1] + 1);
            };
        return f[word1.length()][word2.length()];
    }
};