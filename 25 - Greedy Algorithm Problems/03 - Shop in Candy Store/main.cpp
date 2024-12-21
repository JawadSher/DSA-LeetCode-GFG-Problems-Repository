class Solution {
public:
    vector<int> candyStore(int candies[], int N, int K) {
        // Sort the candies array in ascending order to find minimum cost easily
        sort(candies, candies + N);

        // Variables for calculating minimum cost
        int mini = 0;  // Stores the minimum cost
        int free = N - 1; // Points to the most expensive candy available
        int buy = 0; // Points to the least expensive candy to buy

        // Calculate the minimum cost of buying candies
        while (buy <= free) {
            mini += candies[buy]; // Add the cost of the current candy being bought
            buy++;                // Move to the next candy to buy
            free -= K;            // Reduce the free candies available (K candies become free per purchase)
        }

        // Variables for calculating maximum cost
        int maxi = 0; // Stores the maximum cost
        free = 0;     // Points to the least expensive candy available
        buy = N - 1;  // Points to the most expensive candy to buy

        // Calculate the maximum cost of buying candies
        while (buy >= free) {
            maxi += candies[buy]; // Add the cost of the current candy being bought
            buy--;                // Move to the next candy to buy (from most expensive to least expensive)
            free += K;            // Increase the number of free candies available (from cheapest candies)
        }

        // Return the minimum and maximum costs as a vector
        return {mini, maxi};
    }
};
