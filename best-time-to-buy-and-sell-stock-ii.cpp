
/**
 * best-time-to-buy-and-sell-stock-ii
 * http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii\\/
 * Prob:
 *      Say you have an array for which the ith element is the price of a given stock on day i.
 *      Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 *      (ie, buy one and sell one share of the stock multiple times). 
 *      However, you may not engage in multiple transactions at the same time 
 *      (ie, you must sell the stock before you buy again). 
 * Solution:
 *      scan. record current min and max value, and ensure the current list (min to max) is ascending
 *      every time there is a bent (peak), add curMax - curMin to total profile and reset curMin and curMax
 * CAUTION:
 *
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int totalP = 0;
        int curMin = prices[0];
        int curMax = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (curMax > prices[i])
            {
                totalP += (curMax - curMin);
                curMin = prices[i];
                curMax = prices[i];
            }
            else
                curMax = prices[i];
        }
        return totalP + (curMax - curMin);
    }
};