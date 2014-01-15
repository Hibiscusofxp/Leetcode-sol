/**
 * 3Sum 
 * http://oj.leetcode.com/problems/3sum/
 * Prob:
 *      find all unique non-decending 3 element tuples whose sum is closest to 0
 * Sol:
 *      adapted from 4 sum
 */
class Solution {
public:
    void DFSTillTwoLeft(int level, int idx, int sumLeft, const int len, const vector<int> &arr, vector<int> &curArr, vector< vector <int> > &ans)
    {
        if (idx > arr.size() - 2)
            return;
        if (level > len - 2)
            return;
        if (level == len - 2 )
        {
            int last2 = idx;
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
                    do last --; while (last2 < last && arr[last] == arr[last+1]);
                    do last2 ++; while (last2 < last && arr[last2] == arr[last2-1]);
                }
                else if (thisSumLeft > sumLeft)
                    do last --; while (last2 < last && arr[last] == arr[last+1]);
                else 
                    do last2 ++; while (last2 < last && arr[last2] == arr[last2-1]);
            };
            return;
        };
        while (idx < arr.size() - 2)
        {
            curArr.push_back(arr[idx]);
            DFSTillTwoLeft(level + 1, idx + 1, sumLeft - arr[idx], len, arr, curArr, ans);
            curArr.pop_back();
            do idx ++; while (idx < arr.size() - 2 && arr[idx] == arr[idx-1]);
        }
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector< vector <int> > ans;
        vector<int> curArr;
        if (num.size() < 3)
            return ans;
        sort(num.begin(), num.end());
        DFSTillTwoLeft(0, 0, 0, 3, num, curArr, ans);
        return ans;
    }
}; 