class Solution {
public:
    // Helper function to calculate maximum profit
    int solve(vector<int>& prices, int index, int buy, int limit){
        int n = prices.size();
        
        // Base case: if we've processed all days (index == n) or no more transactions can be made (limit == 0)
        if(index == n || limit == 0) return 0;

        int profit = 0;
        
        // If we are allowed to buy (buy == 1)
        if(buy){
            // Option 1: Buy the stock today and recurse for the next day with the buy flag set to 0 (indicating we can sell next)
            // Option 2: Skip the current day and proceed to the next day with the buy flag still set to 1
            profit = max((-prices[index] + solve(prices, index+1, 0, limit)), 
                          (0 + solve(prices, index+1, 1, limit)));
        } else {
            // If we are allowed to sell (buy == 0)
            // Option 1: Sell the stock today, reduce the transaction limit by 1 and proceed to the next day with buy flag set to 1
            // Option 2: Skip the current day and proceed to the next day with buy flag still set to 0
            profit = max((+prices[index] + solve(prices, index+1, 1, limit-1)), 
                          (0 + solve(prices, index+1, 0, limit)));
        }

        return profit;
    }

    // Main function to return the maximum profit
    int maxProfit(vector<int>& prices) {
        // Starting from day 0, we can buy the stock, and we are allowed to make at most 2 transactions
        return solve(prices, 0, 1, 2);
    }
};
