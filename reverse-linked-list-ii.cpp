
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || m == n)
            return head;
        m --;
        n --;
        ListNode *newHead = head;
        ListNode *tail = head;
        ListNode *pre = NULL;
        while (m > 0)
        {
            pre = head;
            head = head->next;
            m --;
        }
        while (n > 0)
        {
            tail = tail->next;
            n --;
        }
        ListNode *p = tail;
        while (head != tail)
        {
            ListNode *tmp = head;
            head = head->next;
            ListNode *pnext = tail->next;
            tail->next = tmp;
            tmp->next = pnext;
        }
        if (pre == NULL)
        {
            return tail;
        } else
        {
            pre->next = tail;
            return newHead;
        }
    }
};



class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || m == n)
            return head;
        ListNode *pre = NULL, *st = head;
        m --;
        n --;
        for (int i = 0; i < m; i++)
        {
            pre = st;
            st = st->next;
        }
        ListNode *oldPre = pre, *newTail = st;
        for (int i = 0; i < n-m+1; i++)
        {
            ListNode *next = st->next;
            st->next = pre;
            // do not write
            // st = next;
            // pre = st; !!
            pre = st;
            st = next;
        }
        ListNode *newHead = pre, *oldLater = st;
        if (oldPre == NULL)
            head = newHead;
        else
            oldPre->next = newHead;
        newTail->next = oldLater;
        return head;
    }
};