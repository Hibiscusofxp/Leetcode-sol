/**
 * Remove Nth Node From End of List 
 * http://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Prob:
 * Solution:
 *      Step one: find nth element
 *          set two pointers, first = head, second is n steps ahead of first.
 *          Then when second reach the end of list (NULL), first is at the nth place from the end
 *      Step two: delete nth element
 *          copy the value of n+1th element to nth and delete the n+1th element  
 *          be careful about deleting the last node
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *first = head;
        ListNode *second = head;
        for (int i = 0; i < n; i ++)
            second = second->next;
        while (second)
        {
            prev = first;
            first = first->next;
            second = second->next;
        }
        if (first->next != NULL)
        {
            ListNode *trash = first->next;
            first->val = trash->val;
            first->next = trash->next;
            delete trash;
        }
        else
        {
            if (prev != NULL)
                prev->next = NULL;
            else
                head = NULL;
            delete first;
        }
        return head;
    }
};





class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;
        ListNode *second = head;
        for (int i = 0; i < n; i++)
            second = second->next;
        ListNode *first = head, *pre = NULL;
        while (second)
        {
            pre = first;
            first = first->next;
            second = second->next;
        }
        if (pre != NULL)
            pre->next = first->next;
        else
            head = first->next;
        return head;
    }
};