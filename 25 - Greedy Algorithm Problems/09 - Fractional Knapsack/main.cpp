class Solution {
  public:
    // Function to solve the Fractional Knapsack problem
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Create a vector to store pairs where each pair consists of the per unit value
        // and the corresponding (value, weight) pair for each item
        vector<pair<double, pair<int, int>>> v;
        
        // Step 1: Calculate the per unit value (value/weight) for each item and store it
        for(int i = 0; i < val.size(); i++){
            double perUnitValue = 1.0 * val[i] / wt[i];  // Calculate per unit value for the item
            v.push_back({perUnitValue, {val[i], wt[i]}});  // Store the per unit value along with the (value, weight) pair
        }
        
        // Step 2: Sort the vector 'v' in decreasing order based on per unit value
        sort(v.begin(), v.end(), [](pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b){
            return a.first > b.first;  // Comparator to sort by per unit value in descending order
        });
        
        // Step 3: Initialize the total value of the knapsack to 0
        double totalValue = 0.0;

        // Step 4: Start filling the knapsack
        for(int i = 0; i < val.size(); i++){
            int currentWeight = v[i].second.second;  // Get the weight of the current item
            int currentValue = v[i].second.first;  // Get the value of the current item
            double perUnitValue = v[i].first;      // Get the per unit value of the current item
            
            // Step 5: Check if the current item can be fully added to the knapsack
            if(capacity >= currentWeight) {
                totalValue += currentValue;  // Add the full value of the item
                capacity -= currentWeight;   // Decrease the remaining capacity of the knapsack
            } else {
                // If the current item cannot be fully added, add the fractional part of it
                totalValue += capacity * perUnitValue;  // Add the value for the fractional weight
                break;  // Once the knapsack is full, break out of the loop
            }
        }
        
        // Step 6: Return the total value of the knapsack
        return totalValue;
    }
};
