@@@
/**
 * Longest Valid Parentheses
 * http://oj.leetcode.com/problems/longest-valid-parentheses/
 * Prob:
 *      Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * Sol:
 *      maintain a stack. The trick is store the INDEX of parenthese in the stack.
 *      O(n) scan. if it is '(', then push; if it is ')', then 
 *          if the stack.top() refers to an '(', meaning we can use this ')' to make a '(...)' pair
 *              Core trick is that
 *                  must pop stack first, after pop
 *                  if the stack is empty, then it means all '(' and ')'s from the beginning of string can make legal substring 
 *                  if the stack is not empty, it means all '(' and ')'s from (exclusive) the stack.top() can make legal substring
 *              remember of update the ans (max length so far)
 *          if stack.top() is NOT a '(' (empty or ')') , meaning the string is cut off at the point $idx
 *              thus we push(idx) to stack to indicate the string is cut from here
 * CAUTION:
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack <int> stk;
        int ans = 0;
        for (int idx = 0; idx < s.length(); idx++)
        {
            if (s[idx] == '(')
                stk.push(idx);
            else
            {
                if ( (! stk.empty()) && s[ stk.top() ] == '(' )
                {
                    stk.pop();
                    ans = std::max (ans, idx - (stk.empty() ? -1 : stk.top()));
                }
                else
                    stk.push(idx);
            }
        }
        return ans;
    }
};