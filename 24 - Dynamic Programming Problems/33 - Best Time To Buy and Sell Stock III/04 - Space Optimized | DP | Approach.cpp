class Solution {
public:
    // Helper function to calculate the maximum profit using dynamic programming with space optimization
    int solve(vector<int>& prices){
        int n = prices.size();

        // Initialize two 2D vectors: 'curr' to store the current results and 'next' for the next day's results
        // 'curr' and 'next' are of size 2 (buy/sell) and 3 (transaction limits 1 and 2).
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        // Start iterating from the last day (index = n-1) to the first day (index = 0)
        for(int index = n-1; index >= 0; index--){
            // For each index, check if we can buy (buy == 1) or sell (buy == 0), and the remaining transaction limit
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){
                    int profit = 0;

                    // If we can buy (buy == 1)
                    if(buy){
                        // Option 1: Buy the stock today, and move to the next day with the ability to sell and the same remaining transaction limit
                        int buyStock = -prices[index] + next[0][limit];
                        // Option 2: Skip buying and move to the next day, still with the ability to buy and the same remaining transaction limit
                        int notBuyStock = 0 + next[1][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(buyStock, notBuyStock);
                    }else{
                        // If we can sell (buy == 0)
                        // Option 1: Sell the stock today, reduce the transaction limit by 1, and move to the next day with the ability to buy
                        int sellStock = +prices[index] + next[1][limit-1];
                        // Option 2: Skip selling and move to the next day, still with the ability to sell and the same remaining transaction limit
                        int notSellStock = 0 + next[0][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(sellStock, notSellStock);
                    }

                    // Store the computed result for the current index, buy/sell option, and transaction limit in the 'curr' vector
                    curr[buy][limit] = profit;
                }
            }

            // After processing the current index, move the results of 'curr' to 'next' for the next iteration
            next = curr;
        }

        // The final result is stored at curr[1][2], representing the maximum profit starting from day 0,
        // with the ability to buy and 2 transactions allowed.
        return curr[1][2];
    }

    // Main function to return the maximum profit from the given prices array
    int maxProfit(vector<int>& prices) {
        // Call the solve function and return the result
        return solve(prices);
    }
};
