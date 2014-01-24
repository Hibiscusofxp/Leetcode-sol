@@@
/**
 * remove-element
 * http://oj.leetcode.com/problems/remove-element
 * Prob:
 *      Given an array and a value, remove all instances of that value in place and return the new length.
 *      The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * Solution:
 *      scan from begin the end. The trick is to pick up the elements that are NOT EQUAL to the elem and ignore the eles that are the same.
 * CAUTION:
 *
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int newLen = 0;
        for (int i = 0; i < n; i++)
            if (A[i] != elem)
                A[newLen++] = a[i];
        return newLen;
    }
};
