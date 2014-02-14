
/**
 * plus-one
 * http://oj.leetcode.com/problems/plus-one/
 * Prob:
 *  
 * Solution:
 *  
 * CAUTION:
 *
 */

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int idx = digits.size()-1;
        while (idx >= 0 && digits[idx] == 9)
        {
            digits[idx] = 0;            // first time wrong: forgot this line.  use a simple test to debug!
            idx --;
        };
        if (idx < 0)
        {
            digits.insert(digits.begin(), 1);           // second time wrong: digits.insert(0, 1); is wrong!
            return digits;
        }
        else
        {
            digits[idx] ++;
            return digits;
        }
    }
};