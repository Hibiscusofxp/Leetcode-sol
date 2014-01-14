/**
 * remove-duplicates-from-sorted-array
 * http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Prob:
 *      Given a sorted array, remove the duplicates in place 
 *      such that each element appear only once and return the new length.
 * Note:
 *      in-place. Mem O(1)
 * Solution:
 *      Linear scan
 * CAUTION:
 *      check empty array!
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        // CAUTION: check empty!
        if (n == 0)
            return 0;

        int numDiff = 0;
        for (int i = 0; i < n; i ++)
        {
            if (A[i] != A[numDiff])
            {
                numDiff ++;
                A[numDiff] = A[i];
            }
        };
        return numDiff + 1;
    }
};