
/**
 * merge-sorted-array
 * http://oj.leetcode.com/problems/merge-sorted-array/
 * Prob:
 *      Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *      You may assume that A has enough space to hold additional elements from B. 
 * Solution:
 *      scan from back
 *
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int len = m + n - 1;
        m --;
        n --;
        while (m >= 0 || n >= 0)
        {
            if (m >= 0)
            {
                if (n >= 0)
                {
                    if (A[m] > B[n])
                        A[len --] = A[m --];
                    else
                        A[len --] = B[n --];
                }
                else
                    A[len --] = A[m --];
            } 
            else
            {
                A[len --] = B[n --];
            }
        }
        return;
    }
};