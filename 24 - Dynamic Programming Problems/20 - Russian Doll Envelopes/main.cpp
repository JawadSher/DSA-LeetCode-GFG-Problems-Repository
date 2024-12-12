class Solution {
public:
    // Helper function to find the length of the Longest Increasing Subsequence (LIS)
    int solve(vector<int>& heights){
        int n = heights.size();   // Get the number of envelopes
        vector<int> ans;          // Vector to store the LIS of heights (not the actual subsequence, just its length)

        // Iterate through all the heights to find the LIS
        for(int i = 0; i < n; i++){
            // If the ans vector is empty or the current height is greater than the last element of ans,
            // add the current height to the LIS.
            if(ans.empty() || heights[i] > ans.back()){
                ans.push_back(heights[i]);
            } else {
                // Otherwise, find the first element in ans that is greater than or equal to heights[i]
                // and replace it with the current height.
                // This maintains the smallest possible value for the LIS subsequence, ensuring it's extensible.
                int index = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
                ans[index] = heights[i]; // Update the value at the found position
            }
        }

        // Return the size of the LIS (i.e., the maximum number of envelopes that can be nested)
        return ans.size();
    }

    // Main function to solve the Russian Doll Envelopes problem
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort the envelopes
        // Sort first by width in ascending order, and if the widths are the same, by height in descending order
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            // If the widths are equal, we sort by height in descending order
            if(a[0] == b[0]) return a[1] > b[1];
            // Otherwise, sort by width in ascending order
            return a[0] < b[0];
        });

        // Step 2: Extract the heights of the envelopes after sorting
        vector<int> heights;
        for(const auto& envelope : envelopes) heights.push_back(envelope[1]);

        // Step 3: Find the LIS of heights (this will give the maximum number of envelopes that can be nested)
        return solve(heights);
    }
};
