/**
 * Palindrome Number
 * http://oj.leetcode.com/problems/palindrome-number/
 * Notes:
 *      without extra space
 *      How about negative?
 *      is 20 palindrome?
 *      by finding a reverse integer, might overflow:
 *          2 100 000 009 and 9 000 000 012 > LONG_MAX
 * @Solutions:
 *      Find leftmost and rightmost digits, compare and chop
 */

class Solution {
public:
    bool isPalindrome(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (x < 0)
            return false;
        int tmp = x;
        int maxdigit = 1;
        while (tmp >= 10)
        {
            maxdigit *= 10;
            tmp /= 10;
        };
        while (x != 0)
        {
            if ( (x / maxdigit) != (x % 10) )
                return false;
            x = (x % maxdigit) / 10;
            maxdigit /= 100;
        }
        return true;
    }
};