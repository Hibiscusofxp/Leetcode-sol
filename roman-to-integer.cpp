@@@
/**
 * Permutations 2
 * http://oj.leetcode.com/problems/permutations-ii/
 * Prob:
 * Solution:
 *      sort first then DFS. in each try check whether current value has been used before
 * CAUTION:
 *      syntac about declaring empty vector
 */
class Solution {
    
    void DFSPerGen(int idx, const int len, const vector<int> &arr, vector<bool> &visited, vector<int> &thisPer, vector< vector <int> > &totalAns)
    {
        if (idx == len)
        {
            totalAns.push_back(thisPer);
            return;
        }
        for (int i = 0; i < len; ++i)
            if (! visited[i])
            {
                // core statement
                if ( i > 0 && arr[i] == arr[i-1] && (! visited[i-1]))
                    continue;
                thisPer[idx] = arr[i];
                visited[i] = true;
                DFSPerGen(idx + 1, len, arr, visited, thisPer, totalAns);
                visited[i] = false;
            }
    };

public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<bool> visited(num.size(), false);
        vector<int> thisPer(num.size(), 0);
        vector< vector<int> > totalAns;
        // DO NOT USE vector< vector<int> > totalAns();

        sort(num.begin(), num.end());
        DFSPerGen(0, num.size(), num, visited, thisPer, totalAns);
        return totalAns;
    };
    

};