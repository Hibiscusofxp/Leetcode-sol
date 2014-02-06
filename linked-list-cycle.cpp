
/**
 * linked-list-cycle
 * http://oj.leetcode.com/problems/linked-list-cycle
 * Prob:
 *      Given a linked list, determine if it has a cycle in it.
 *      Can you solve it without using extra space?
 * Solution:
 *      maintain fast and slow pointers
 * CAUTION:
 *      Careful about the situation when fast and slow both reaches null when the list only has one element
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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = (fast->next != NULL ? fast->next->next : NULL);
            if (fast != NULL && slow == fast)
            // careful the situation when fast and slow are both null
                return true;
        }
        return false;
    }
};