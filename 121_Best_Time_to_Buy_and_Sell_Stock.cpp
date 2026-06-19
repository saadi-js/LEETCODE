/*
Problem 121. Best Time to Buy and Sell Stock

Problem Statement:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve. If no profit is possible, return 0.

Intuition:
We want to find the best pair (buy day, sell day) such that:
sell price - buy price is maximized.

Instead of checking all pairs (O(n²)), we track the minimum price seen so far
and compute profit at each step.

Key Idea:
At each day:
- bestBuy = minimum price seen so far
- potential profit = current price - bestBuy

We update:
- maxProfit if current profit is higher
- bestBuy if current price is lower

Approach:
1. Initialize bestBuy as first price.
2. Initialize maxProfit = 0.
3. Traverse array from day 1 onward.
4. For each price:
   a. Compute profit if sold today.
   b. Update maxProfit.
   c. Update bestBuy if current price is lower.
5. Return maxProfit.

Example:
prices = [7,1,5,3,6,4]

Step-by-step:
bestBuy = 1
maxProfit = 5 (6 - 1)

Why This Works:
We always ensure buy happens before sell.
Tracking minimum so far guarantees optimal buy point for every future sell.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern Used:
Greedy + Single Pass Tracking (Min/Max Optimization)

Key Learning:
Whenever you need max difference with ordering constraint:
→ Track minimum so far and compute best result greedily
*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Stores maximum profit found
        int maxProfit = 0;

        // Tracks minimum price seen so far (best day to buy)
        int bestBuy = prices[0];

        // Traverse prices starting from second day
        for(int i = 1; i < prices.size(); i++)
        {
            // If selling today gives profit
            if(prices[i] > bestBuy)
            {
                // Update maximum profit
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }

            // Update best buy price if current is lower
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
    }
};
