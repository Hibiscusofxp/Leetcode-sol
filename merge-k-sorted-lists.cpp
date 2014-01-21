/**
 * Merge k Sorted Lists 
 * http://oj.leetcode.com/problems/merge-k-sorted-lists/
 * Prob:
 *      Merge k sorted linked lists and return it as one sorted list.
 * Solution:
 *      One:
 *          merge two lists each time O(k*totalNumberOfEles)
 *          to improve, merge two lists AT TWO ENDPOINTS each time O(k* log(totalNumberOfEles))
 *      Two:
 *          Use min heap or STL multiset to store first elements in each list
 *          (However, Leetcode does not seem to support factor.. meaning multiset is not applicable here lacking the comparator)
 * CAUTION:
 *      check if found in hash table:
 *          if (hashValtoIdx.find(left) != hashValtoIdx.end())
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *merge2Lists(ListNode* l1, ListNode* l2)
    {
        ListNode *head = NULL, *tail = NULL;
        while (l1 || l2)
        {
            ListNode *p = NULL;
            int tmp = -1;
            if (l1 && ( !p || (p->val > l1->val) ))
            {
                p = l1;
                tmp = 1;
            };
            if (l2 && ( !p || (p->val > l2->val) ))
            {
                p = l2;
                tmp = 2;
            };
            if (tmp == 1)
                l1 = l1 -> next;
            else
                l2 = l2 -> next;
            if (! tail)
                head = p;
            else
                tail->next = p;
            tail = p;
        }
        return head;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        int len = lists.size();
        while (len > 1)
        {
            for (int i = 0; i < (len/2); i++)
                lists[i] = merge2Lists(lists[i], lists[len - 1 - i]);
            len -= len/2;
        }
        return lists[0];
    }
};
