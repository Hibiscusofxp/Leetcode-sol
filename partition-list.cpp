
/**
 * partition-list
 * http://oj.leetcode.com/problems/partition-list/
 * Prob:
 *      Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * Solution:
 *      scan and done
 *
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *lptr = NULL, *lhead = NULL, *rptr = NULL, *rhead = NULL;
        while (head != NULL)
        {
            if (head->val < x)
            {
                if (lhead == NULL)
                {
                    lhead = head;
                    lptr = head;
                }
                else
                {
                    lptr->next = head;
                    lptr = head;
                }
            }
            else
            {
                if (rhead == NULL)
                {
                    rhead = head;
                    rptr = head;
                }
                else
                {
                    rptr->next = head;
                    rptr = head;
                }
            }
            head = head->next;
        };
        if (lhead == NULL)
            return rhead;
        else 
            lptr->next = NULL;
        if (rhead == NULL)
            return lhead;
        else
            rptr->next = NULL;
        lptr->next = rhead;
        return lhead;

    }
};
