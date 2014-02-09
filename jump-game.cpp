
/**
 * jump-game
 * http://oj.leetcode.com/problems/jump-game/
 * Prob:
 *      Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *      Each element in the array represents your maximum jump length at that position.
 *      Determine if you are able to reach the last index.
 * Solution:
 *      The code is self explainary enough :)
 * CAUTION:
 *      Do not use DP, which is actually O(n^2)
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        int furthest = 0;
        for (int i = 0; i < n; i++)
            if (furthest >= i)
                furthest = max(furthest, i + A[i]);
            else
                return false;
        return (furthest >= n - 1);
    }
};