
/**
 * multiply-strings/
 * http://oj.leetcode.com/problems/multiply-strings/
 * Prob:
 *  
 * Solution:
 *  
 * CAUTION:
 *
 */
class Solution {
public:
    
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int len = len1 + len2 - 1;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector <int> resi(len , 0);
        for (int i = 0; i < len1; i++ ) {
            for (int j = 0; j < len2; j++) {
                resi[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        string res;
        for (int i = 0; i < len; i++) {
            if (i == len-1 && resi[i] > 9) {
                resi.push_back(0);
                len ++;
            }
            if (resi[i] > 9) {
                resi[i + 1] += resi[i] / 10;
                resi[i] %= 10;
            }
            res = res + char(resi[i] + '0');
        }
        reverse(res.begin(), res.end());
        
        // trim leading zeros!
        while (res.size() > 1 && res[0] == '0')
            res.erase(0,1);
        return res;
    }
};