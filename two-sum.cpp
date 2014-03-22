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
        unordered_map <int, int> hashv2i;
        vector <int> res;
        for (int i = 0; i < numbers.size(); i++)
            hashv2i[target - numbers[i]] = i + 1;
        for (int i = 0; i < numbers.size(); i++)
            if (hashv2i.find(numbers[i]) != hashv2i.end() )
            {
                if (i+1 != hashv2i[numbers[i]])
                    // cannot be same number
                {
                    res.push_back(min (i+1, hashv2i[numbers[i]]) );
                    res.push_back(max (i+1, hashv2i[numbers[i]]) );
                    return res;
                }
            }
        return res;
    }
};