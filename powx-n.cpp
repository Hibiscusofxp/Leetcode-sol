/**
 * Pow(x,n)
 * http://oj.leetcode.com/problems/powx-n/
 * Prob:
 *      Implement pow(x,n)
 * Solution:
 *      divide-and-conquer
 *      recurrsive
 * CAUTION:
 *      check whether n is 0 or NEGATIVA!
 *      DO NOT USE PosPow(x, -n) when n is negative.
 *          n could be -2^32 and -n = 2^32 causes overflow
 *      Do NOT USE n >> 1 when n is negative
 */
class Solution {
public:
    double PosPow(double x, int n);
    double pow(double x, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
    if (n >= 0)
        return PosPow(x, n);
    else
        return (1.0 / PosPow(x, n));
    // Do not use PosPow(x, -n) here!
    }
};

// REQUIRES: n >= 0
// EFFECTS: Calc x^(|n|). n might be either positive or negative
double Solution::PosPow(double x, int n)
{
    if (n == 0)
        return 1.0;
    double tmp = PosPow(x, n / 2);
    // do not use n >> 1 here
    if ((n & 1) == 0)
        return tmp * tmp;
    else
        return tmp * tmp * x;
};