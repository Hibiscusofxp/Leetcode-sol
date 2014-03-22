
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
class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        for (int i = 0; i < s.length(); i ++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    stk.push(s[i]);
                    break;
                case ')':
                    if ( (! stk.empty()) && (stk.top() == '(') ) {
                        stk.pop();
                        break;
                    } else {
                        return false;
                    }
                case ']':
                    if ( (! stk.empty()) && (stk.top() == '[') ) {
                        stk.pop();
                        break;
                    } else {
                        return false;
                    }
                case '}':
                    if ( (! stk.empty()) && (stk.top() == '{') ) {
                        stk.pop();
                        break;
                    } else {
                        return false;
                    }
                default:
                    return false;
            }
        }
        // DO not use return true; need to check empty!!
        return (stk.empty());
    }
};