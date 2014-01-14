/**
 * Copy List with Random Pointer 
 * http://oj.leetcode.com/problems/copy-list-with-random-pointer/
 * Prob:
 *      A linked list is given such that each node contains an additional random pointer 
 *      which could point to any node in the list or null.
 *      Return a deep copy of the list.
 * Solution:
 *      loop two times. first time construct the list (allocate memory), second time set tup links
 * CAUTION:
 *      check NULL of hash table index
 */
 /**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        unordered_map <RandomListNode*, RandomListNode*> hashOld2New;
        RandomListNode* p = head;
        while (p != NULL)
        {
            RandomListNode* q = new RandomListNode (p->label);
            hashOld2New[p] = q;
            // hashOld2New.put(p, q);
            p = p->next;
        }
        p = head;
        while (p != NULL)
        {
            hashOld2New[p]->next = (p->next == NULL? NULL : hashOld2New[p->next]);
            hashOld2New[p]->random = (p->random == NULL? NULL : hashOld2New[p->random]);
            // check p->next is NULL or not
            // do not write hashOld2New[p]->next = hashOld2New[p->next];
            p = p->next;
        }
        return hashOld2New[head];
    }
};