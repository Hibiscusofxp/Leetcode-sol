
/**
 * longest-palindromic-substring
 * http://oj.leetcode.com/problems/longest-palindromic-substring
 * Prob:
 *  
 * Solution:
 *  
 * CAUTION:
 *
 */

class Solution {
    string longestFrom(const string str, int st, int ed) {
        while (st >= 0 && ed < str.length() && str[st] == str[ed]) {
            st --;
            ed ++;
        }
        return str.substr(st + 1, ed - st - 1);
    }
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max = 0;
        string res = "";
        for (int i = 0; i < len; i ++) {
            string tmp = longestFrom(s, i, i);
            if ( max < tmp.length()) {
                max = tmp.length();
                res = tmp;
            }
        }

        for (int i = 0; i < len-1; i++) {
            string tmp = longestFrom(s, i, i+1);
            if (max < tmp.length() ) {
                max = tmp.length();
                res = tmp;
            }
        }

        return res;

    }
};