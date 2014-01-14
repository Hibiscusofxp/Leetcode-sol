/** 
 * Single Number
 * http://oj.leetcode.com/problems/single-number/
 * Notes:
 *      Given an array of integers, every element appears twice except for one.
 *      Find that single one.
 *      Time: O(n)
 *      Mem: O(1)
 * @Solutions:
 *      xor all elements
 */

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans ^ A[i];
        }
        return ans;
    }
};