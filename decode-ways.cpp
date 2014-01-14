/**
 * Decode Ways
 * http://oj.leetcode.com/problems/decode-ways/
 * Solution:
 *      DP
 * CAUTION:
 *      Case discussion
 */
class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if ("" == s)
            return 0;
        int *f = new int [s.size()];
        if (s[0] == '0')
            return 0;
        f[0] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (s[i-1] == '2' || s[i-1] == '1')
                    f[i] = (i == 1? 1 : f[i-2]);
                else
                    return 0;
            }
            else
            {
                f[i] = f[i-1];
                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6') )
                    f[i] += ( i == 1 ? 1 : f[i-2]);
            }
        }
        int ans = f[s.size()-1];
        delete [] f;
        return ans;
    }
};