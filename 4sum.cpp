@@@
/**
 * 4Sum 
 * http://oj.leetcode.com/problems/4sum/
 * Prob:
 *      find all unique non-decending 4 element tuples whose sum is closest to target
 * General solution to m-sum:
 *      presort and DFS the find first m - 2 elements except the last two O(n^(m-2))
 *      Four last two, set two index pointers, one $last2 at the begin, the other $last at the end. 
 *          try moving $last2 and $last to the middle, if the sum is greater than targer, move last; if sum less than target, move last2
 * CAUTION:
 *      dealing with duplication. use do while here not while do
*/
class Solution {
public:
    // level: how many elements that have been added. 0 .. m
    // idx: current idx in the original arr 0..arr.size()
    // sumLeft: how close the current sum and target is. start from target
    // len: m  in "m Sum"
    // arr: input numbers
    // curArr: numbers that have been added currently
    // ans : answer
    void DFSTillTwoLeft(int level, int idx, int sumLeft, const int len, const vector<int> &arr, vector<int> &curArr, vector< vector <int> > &ans)
    {
        if (idx > arr.size() - 2)
            return;
        if (level > len - 2)
            return;
        if (level == len - 2 )
        {
            int last2 = idx;
            // NOT arr.size() here!
            int last = arr.size() - 1;
            int thisSumLeft;
            while (last2 < last)
            {
                thisSumLeft = arr[last2] + arr[last];
                if ( thisSumLeft == sumLeft)
                {
                    curArr.push_back(arr[last2]);
                    curArr.push_back(arr[last]);
                    ans.push_back(curArr);
                    curArr.pop_back();
                    curArr.pop_back();
                    // Prevent duplication
                    do last --; while (last2 < last && arr[last] == arr[last+1]);
                    do last2 ++; while (last2 < last && arr[last2] == arr[last2-1]);
                }
                else if (thisSumLeft > sumLeft)
                    // Prevent duplication
                    do last --; while (last2 < last && arr[last] == arr[last+1]);
                else 
                    // Prevent duplication
                    do last2 ++; while (last2 < last && arr[last2] == arr[last2-1]);
            };
            return;
        };
        while (idx < arr.size() - 2)
        {
            curArr.push_back(arr[idx]);
            DFSTillTwoLeft(level + 1, idx + 1, sumLeft - arr[idx], len, arr, curArr, ans);
            curArr.pop_back();
            // Prevent duplication
            do idx ++; while (idx < arr.size() - 2 && arr[idx] == arr[idx-1]);
        }
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector< vector <int> > ans;
        vector<int> curArr;
        // deal with empty input
        if (num.size() < 4)
            return ans;
        sort(num.begin(), num.end());
        DFSTillTwoLeft(0, 0, target, 3, num, curArr, ans);
        return ans;
    }
}; 