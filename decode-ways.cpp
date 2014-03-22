/**
 * Decode Ways
 * http://oj.leetcode.com/problems/decode-ways/
 * Solution:
 *      DP
 * CAUTION:
 *      Case discussion
 */
class Solution {
    bool valid (char c1, char c2) {
        if (c1 == '0')
            return false;
        if (c1 == '1' || c1 == '2' && c2 <= '6')
            return true;
        return false;
    }
public:
    int numDecodings(string s) {
        if (s == "")
            return 0;
        vector <int> f (s.size(), 0);
        if (s[0] == '0')
            return 0;
        f[0] = 1;
        if (s[1] != '0')
            f[1] = f[0];
        // move out of for loop since f[i-2] does not exist
        if (valid(s[0], s[1]))
            f[1] ++;
        
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != '0')
                f[i] += f[i-1];
            if (valid (s[i-1], s[i]) ) {
                f[i] += f[i-2];
            }
        }
        return f[s.size() - 1];
    }
};