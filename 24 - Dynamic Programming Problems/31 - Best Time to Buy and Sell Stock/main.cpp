class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum price to the first day's price
        int mini = prices[0];
        
        // Initialize the maximum profit to 0
        int profit = 0;

        // Iterate through the price list starting from the second day
        for(int i = 1; i < prices.size(); i++) {
            // Calculate the potential profit if the stock is sold on the current day
            int diff = prices[i] - mini;

            // Update the maximum profit if the current profit is higher
            profit = max(profit, diff);

            // Update the minimum price seen so far
            mini = min(mini, prices[i]);
        }

        // Return the maximum profit found
        return profit;
    }
};
