/**
 * Clone Graph
 * http://oj.leetcode.com/problems/clone-graph/
 * Prob:
 *      Given an array of int, find two numbers such that they add up to a specific target number.
 *      return indexs
 * Solution:
 *      hash table, map value to index
 * CAUTION:
 *      check if found in hash table:
 *          if (hashValtoIdx.find(left) != hashValtoIdx.end())
 */

 /**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        
        unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> hashOld2New;
        queue< UndirectedGraphNode* > q;
        q.push(node);
        hashOld2New[node] = new UndirectedGraphNode(node->label);
        while (! q.empty())
        {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            for (int i = 0; i < cur->neighbors.size(); i++)
            {
                UndirectedGraphNode* curN = cur->neighbors[i];
                if (hashOld2New.find(curN) == hashOld2New.end())
                {
                    UndirectedGraphNode* newN = new UndirectedGraphNode(curN->label);
                    hashOld2New[curN] = newN;
                    q.push(newN);
                    hashOld2New[cur]->neighbors.push_back(curN);
                }
                else
                    hashOld2New[cur]->neighbors.push_back(hashOld2New[curN]);
            }
        }
        return hashOld2New[node];
    }
};