
/**
 * best-time-to-buy-and-sell-stock
 * http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Prob:
 *      Say you have an array for which the ith element is the price of a given stock on day i.
 *      If you were only permitted to complete at most one transaction 
 *      (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * Solution:
 *      scan, record the current minimum price and update the max profile every time
 * CAUTION:
 *      stock is BOUGHT FIRST and SOLD LATER, so it is to find the ascending list rather than decending
 *
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxP = 0;
        int curMin = -1;
        for (int i = 0; i < prices.size(); i++)
        {
            if (curMin == -1 || curMin > prices[i])
                curMin = prices[i];
            else maxP = max(maxP, prices[i] - curMin);
        };
        return maxP;
    }
};