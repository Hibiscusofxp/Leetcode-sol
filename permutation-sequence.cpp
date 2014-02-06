
/**
 * permutation-sequence
 * http://oj.leetcode.com/problems/permutation-sequence/
 * Prob:
 *      Given n and k, return the kth permutation sequence.
 * Solution:
 *      Think as mathmatician. We set the most significiant digit by observing that the rest n-1 digits could make (n-1)! different pairs at once,
 *          so the first digit could be calculated by d0 = k / (n-1)!, also k2 = k % (n-1)!, d1 = k2 % (n-2)!...
 *      Also, be careful that numbers could only be used once so you should keep track of its usage as well (here by setting a ref string)
 * CAUTION:
 *      Small details and wired modifications on value to accord the index start from 0..
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string ref = "";
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
            ref += char(i + '0');
        };
        // change range of k from (1,n) to (0, n-1)
        k --;
        string ans = "";
        for (int i = n; i >= 1; i--)
        {
            // divide fact first
            fact /= i;
            ans += ref[k/fact];
            ref.erase(k/fact, 1);
            k %= fact;
        };
        return ans;
    }
};