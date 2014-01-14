/**
 * Add Two Numbers 
 * http://oj.leetcode.com/problems/add-two-numbers/
 * Prob:
 * Solution:
 *      two scan loops
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1; 
        ListNode *ans, *p, *p1, *p2;
        ans = new ListNode(l1->val + l2->val);
        p = ans;
        p1 = l1->next;
        p2 = l2->next;
        while ((p1 != NULL) || (p2 != NULL))
        {
            ListNode *tmp = new ListNode(0);
            tmp->val += (p1 != NULL ? p1->val : 0);
            tmp->val += (p2 != NULL ? p2->val : 0);
            p->next = tmp;
            p = tmp;
            p1 = ( p1 != NULL ? p1->next : NULL);
            p2 = ( p2 != NULL ? p2->next : NULL);
        }
        p = ans;
        while (p != NULL)
        {
            if (p->val > 9)
            {
                if (p->next == NULL)
                    p->next = new ListNode(0);
                p->next->val += p->val / 10;
                p->val = p->val % 10;
            }
            p = p->next;
        }
        return ans;
    }
};