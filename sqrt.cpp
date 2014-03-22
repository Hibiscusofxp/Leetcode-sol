
/**
 * 
 * http://oj.leetcode.com/problems/
 * Prob:
 *  
 * Solution:
 *  
 * CAUTION:
 *
 */
class Solution {
public:
    int sqrt(int x) {
        if (x < 0)
            return -1;
        if (x == 0)
            return 0;
        if (x ==1 )
            return 1;
        int low = 0;
        int high = min(x, 46341);
        // 46340^2 < MAX_INT < 46341^2
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (mid * mid > x) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return low;
    }
};