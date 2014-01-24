@@@
/**
 * Reorder List 
 * http://oj.leetcode.com/problems/reorder-list/
 * Prob:
 *      Given 1->2->3->4, return 1->4->2->3
 * Note:
 *      in-place without altering node's value
 * Solution:
 *      1. Find mid node using slow and fast pointer
 *      2. reverse second half list
 *      3. merger two lists
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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        // if empty
        if (head == NULL)
            return;
        //1. Find mid node using slow and fast pointer
        ListNode* fast = head;
        ListNode* slow = head;
        while (true)
        {
            fast = fast->next;
            if (NULL == fast)
                break;
            fast = fast->next;
            if (NULL == fast)
                break;
            slow = slow->next;
        };

        // if only one or two elements
        if (slow == NULL)
            return;

        //2. reverse second half list
        ListNode* cur = slow;
        ListNode* newPrev = cur->next;
        cur->next = NULL;
        while (newPrev != NULL)
        {
            ListNode* newNewPrev = newPrev->next;
            newPrev->next = cur;
            cur = newPrev;
            newPrev = newNewPrev;
        }

        //3. merger two lists
        ListNode* first = head;
        ListNode* second = cur;
        //ASSUME here, either firstList.size() == secondList.size()
        //      or firstList.size() == secondList.size() + 1
        while (first != NULL && second != NULL
            && first != second)
            // If there are odd # of nodes, eventually first == second  
        {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            second->next = firstNext;
            first->next = second;
            first = firstNext;
            second = secondNext;
        }
        return;
    }
};