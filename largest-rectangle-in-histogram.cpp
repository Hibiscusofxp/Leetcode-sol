@@@@
/**
 * Largest Rectangle in Histogram 
 * http://oj.leetcode.com/problems/largest-rectangle-in-histogram/
 * Prop:
 * Solutions:
 *      Trival:     O(n^2), scan for each peak (end of ascending sub sequence), and for each peak, scan back to find the biggest possible area which ends in this peak
 *      Tricky:     O(n)
 *          idea behind: for bricks after a PEAK, the height of that peak brick is actually useless since the brick RIGHT AFTER the peak must be lower than that peak.
 *              that make it possible to merge the brick RIGHT AFTER the peak brick and the peak brick (and possibly more previous bricks)
 *          algo:   maintain two stack, one recording the height of brick of BLOCK of bricks and the one recording the width(initially 1).
 *              for each brick in, push into stack if it is higher than stack.top();
 *              if not, update $maxArea with stack.top() and merge previous bricks if previous bricks are also higher than then input brick and update $maxArea
 *              merge the input brick with block of bricks obtained from above stop, setting the height to be the height of input brick.
 *              ONE MORE: to ensure algo could deal with the last brick properly, put a addtional brick with height 0 at the end of original bricks to empty the stack
 */
 class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> stkHeight;
        stack<int> stkWidth;
        height.push_back(0);
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (stkHeight.empty() || stkHeight.top() < height[i])
            {
                stkHeight.push(height[i]);
                stkWidth.push(1);
            }
            else
            {
                int curW = 0;
                while (! stkHeight.empty() && stkHeight.top() >= height[i])
                {
                    curW += stkWidth.top();
                    maxArea = max( maxArea, stkHeight.top() * curW);
                    stkHeight.pop();
                    stkWidth.pop();
                }
                stkHeight.push(height[i]);
                stkWidth.push(curW + 1);
            }
        }
        return maxArea;
    }
};
