@@@
/**
 * 3 Sum Closest
 * http://oj.leetcode.com/problems/3sum-closest/
 * Prob:
 *      for all 3 element tuples, find the sum which is closest to target
 * CAUTION:
 */
class Solution {
public:
    // CAUTION: use &ans if you want to change the value of ans outside
    void DFSTillTwoLeft(int level, int idx, const int target, int curSum, const int len, const vector<int> &arr, int &ans)
    {
        // optimization. if there are already three ints whose sum equals to target, then no need to proceed
        if (ans == target)
            return;
        if (idx > arr.size() - 2)
            return;
        if (level > len - 2)
            return;
        if (level == len - 2 )
        {
            int last2 = idx;
            int last = arr.size() - 1;
            int thisSum;
            while (last2 < last)
            {
                thisSum = curSum + arr[last2] + arr[last];
                if ( thisSum == target)
                {
                    ans = thisSum;
                    return;
                    // do last --; while (last2 < last && arr[last] == arr[last+1]);
                    // do last2 ++; while (last2 < last && arr[last2] == arr[last2-1]);
                }
                else if (thisSum > target)
                {
                    if ( abs(ans - target) > thisSum - target)
                        ans = thisSum;
                    do last --; while (last2 < last && arr[last] == arr[last+1]);
                }
                else
                {
                    if ( abs(ans - target) > target - thisSum)
                        ans = thisSum;
                    do last2 ++; while (last2 < last && arr[last2] == arr[last2-1]);
                }
            };
            return;
        };
        while (idx < arr.size() - 2)
        {
            DFSTillTwoLeft(level + 1, idx + 1, target, curSum + arr[idx], len, arr, ans);
            do idx ++; while (idx < arr.size() - 2 && arr[idx] == arr[idx-1]);
        }
    }
    int threeSumClosest(vector<int> &num, int target) {
        // do not set 0 or target here
        int ans = 2100000000;
        sort(num.begin(), num.end());
        DFSTillTwoLeft(0, 0, target, 0, 3, num, ans);
        return ans;
    }
}; 