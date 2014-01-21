
/**
 * Restore ip address
 * http://oj.leetcode.com/problems/restore-ip-addresses
 * Prob:
 *      Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *      given "25525511135",
 *      return ["255.255.11.135", "255.255.111.35"] 
 * Solution:
 *      three loops to determine '.'s and check
 * CAUTION:
 *      s.length() is of type size_t. size_t is unsigned!
 *      when s.length() == 2, for example, s.length() - 3 is less than 0, which could unexpectedly result in 23423155145234233 or what..
 */
class Solution {
    bool isValid(string s)
    {
        if (s == "")
            return false;
        if (s[0] == '0' && s.length() > 1)
            return false;
        if (atoi(s.c_str()) > 255)
            return false;
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        std::vector<string> ans;
        // CHECK empty
        if (s == "")
            return ans;
        // CAUTION: use <= instead of < here.
        // d1, d2, d3 is 1..12 or less, while index of s is 0..11 or less
        for (int d1 = 1; d1 <= (int)s.length() - 3; d1++)
            // IMPORTANT!! cast to int here
            for (int d2 = d1+1; d2 <= (int)s.length() - 2; d2++)
                for (int d3 = d2+1; d3 <= (int)s.length() - 1; d3++)
                    string s1 = s.substr(0, d1 - 1 + 1);
                    string s2 = s.substr(d1-1 + 1, d2 - d1);
                    string s3 = s.substr(d2-1 + 1, d3 - d2);
                    string s4 = s.substr(d3-1 + 1, (int)s.length() - d3);
                    if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                            ans.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
        return ans;
    };
 };
