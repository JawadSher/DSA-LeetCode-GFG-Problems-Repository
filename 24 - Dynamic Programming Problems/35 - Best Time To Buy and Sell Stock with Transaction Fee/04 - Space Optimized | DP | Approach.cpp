class Solution {
public:
    // Helper function to calculate the maximum profit with transaction fee using dynamic programming (optimized space approach)
    int solve(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array
        
        // Initialize two arrays to store the maximum profit for the current and next states.
        // 'curr' will represent the current state (profit at index 'index'), 
        // 'next' will represent the state for the next index (future state).
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        // Iterate backwards through the prices array starting from the last index
        for(int index = n-1; index >= 0; index--) {
            // Iterate through both possible states: buy (1) or sell (0)
            for(int buy = 0; buy <= 1; buy++) {

                int profit = 0;

                // If we are in a "buy" state (buy == 1), we have two options:
                // 1. Buy the stock at the current price (represented by -prices[index]) and 
                //    move to the next index where we are in a "sell" state (next[0]).
                // 2. Do nothing and stay in the "buy" state at the next index (next[1]).
                if(buy) {
                    int buyStock = -prices[index] + next[0];  // Buy stock
                    int notBuyStock = 0 + next[1];  // Do nothing (stay in the "buy" state)
                    profit = max(buyStock, notBuyStock);  // Take the maximum of these two options
                } else {
                    // If we are in a "sell" state (buy == 0), we have two options:
                    // 1. Sell the stock at the current price and subtract the fee (represented by +prices[index] - fee)
                    //    and move to the next index where we are in a "buy" state (next[1]).
                    // 2. Do nothing and stay in the "sell" state at the next index (next[0]).
                    int sellStock = +prices[index] - fee + next[1];  // Sell stock and pay the fee
                    int notSellStock = 0 + next[0];  // Do nothing (stay in the "sell" state)
                    profit = max(sellStock, notSellStock);  // Take the maximum of these two options
                }

                // Store the calculated profit for the current state in the 'curr' array
                curr[buy] = profit;
            }

            // Move the current state (curr) to the next state (next) for the next iteration
            next = curr;
        }

        // Return the maximum profit starting from index 0 with the possibility of buying the stock (buy = 1)
        return next[1];
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array
        return solve(prices, fee); // Call the solve function to calculate the maximum profit
    }
};
