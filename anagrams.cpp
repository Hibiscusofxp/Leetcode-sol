
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
    vector<string> anagrams(vector<string> &strs) {
        unordered_map <string, vector <string> * > hashkv;
        for (int i = 0; i < strs.size(); i++) {
            string strkey= strs[i];
            sort(strkey.begin(), strkey.end());
            if (hashkv.find(strkey) == hashkv.end() ) {
                hashkv[strkey] = new vector <string> ();
            }
            hashkv[strkey]->push_back(strs[i]);
        };
        std::vector<string> res;
        for (auto it = hashkv.begin(); it != hashkv.end(); ++it) {
            if (it->second->size() >= 2) {
                for (auto vit = it->second->begin(); vit != it->second->end(); ++vit) {
                    res.push_back(*vit);
                }
            }
        }
        return res;
    }
};




class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // hash all strings
        vector <string> res;
        unordered_map < string, int > hashOld2New;
        for (int i=0; i < strs.size(); i++)
        {
            // for each string, if found in hash, then put into multimap
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (hashOld2New.find(tmp) != hashOld2New.end())
            {
                if (hashOld2New[tmp] != -1)
                {
                    res.push_back(strs [ hashOld2New[tmp] ]);
                    hashOld2New[tmp] = -1;
                }
                res.push_back(strs[i]);
            }
            else
                hashOld2New[tmp] = i;
        }
        return res;
    }
};
