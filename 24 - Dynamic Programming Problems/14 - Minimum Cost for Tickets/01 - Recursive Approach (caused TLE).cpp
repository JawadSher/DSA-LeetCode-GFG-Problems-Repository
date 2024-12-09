class Solution {
public:
    // Recursive function to calculate the minimum cost starting from 'index'
    int getMinCost(vector<int>& days, vector<int>& costs, int n, int index) {
        // Base case: if the index is out of bounds, there is no cost
        if (index >= n) 
            return 0;

        // **Cost for a 1-day pass**:
        // Recursively calculate the cost for the next day and add the cost of a 1-day pass
        int cost1 = getMinCost(days, costs, n, index + 1) + costs[0];
        
        // **Cost for a 7-day pass**:
        // Move forward to the first day that is not covered by a 7-day pass
        int i; 
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        // Recursively calculate the cost from that day and add the cost of a 7-day pass
        int cost7 = getMinCost(days, costs, n, i) + costs[1];
        
        // **Cost for a 30-day pass**:
        // Move forward to the first day that is not covered by a 30-day pass
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        // Recursively calculate the cost from that day and add the cost of a 30-day pass
        int cost30 = getMinCost(days, costs, n, i) + costs[2];

        // Return the minimum of the three costs
        return min(cost1, min(cost7, cost30));
    }

    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Start the calculation from the first day
        return getMinCost(days, costs, days.size(), 0);
    }
};
