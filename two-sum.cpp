@@@
/**
 * Two Sum 
 * http://oj.leetcode.com/problems/two-sum/
 * Prob:
 *      Given an array of int, find two numbers such that they add up to a specific target number.
 *      return indexs
 * Solution:
 *      hash table, map value to index
 * CAUTION:
 *      check if found in hash table:
 *          if (hashValtoIdx.find(left) != hashValtoIdx.end())
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hashValtoIdx;
        vector <int> res;
        for (int i = 0; i < numbers.size(); i++)
            hashValtoIdx[ numbers[i] ] = i;
        for (int i = 0; i < numbers.size(); i++)
        {
            int left = target - numbers[i];
            //if (hashValtoIdx[left] != 0)          // DO NOT USE THIS!
            if (hashValtoIdx.find(left) != hashValtoIdx.end())
            {
                res.push_back(i+1);
                res.push_back(hashValtoIdx[left]+1);
                return res;
            }
        }
    }
};