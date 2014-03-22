
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *pre = NULL, *st = head, *ed;
        while (st != NULL)
        {
            ed = st;
            for (int i = 1; i < k; i++)
            {
                ed = ed->next;
                if (ed == NULL)
                    return head;
            }
            while (st != ed)
            {
                ListNode *tmp = st;
                st = st->next;
                ListNode *pnext = ed->next;
                ed->next = tmp;
                tmp->next = pnext;
            }
            if (pre == NULL)
            {
                head = ed;
            } else
            {
                pre->next = ed;
            }
            st = ed;
            for (int i = 0; i < k; i++)
            {
                pre = st;
                st = st->next;
            }
        }
        return head;
    }
};