class Solution {
  public:
    // Function to find the minimum difference between the maximum and minimum values of m selected elements
    int findMinDiff(vector<int>& a, int m) {
        
        // Step 1: Sort the array to bring the closest values together
        sort(a.begin(), a.end());
        
        // Step 2: Initialize two pointers, i and j, to represent the window of m elements
        int i = 0;
        int j = m - 1;
        
        // Step 3: Initialize the variable 'mini' to store the minimum difference found
        int mini = INT_MAX;
        
        // Step 4: Iterate through the array using the sliding window approach
        // The window size is m elements
        while (j < a.size()) {
            // Calculate the difference between the maximum and minimum values in the current window (a[j] and a[i])
            int diff = a[j] - a[i];
            
            // Step 5: Update 'mini' with the smaller value between the current minimum difference and the calculated difference
            mini = min(mini, diff);
            
            // Move the window: increment both i and j to check the next possible set of m elements
            i++;
            j++;
        }
        
        // Step 6: Return the minimum difference found
        return mini;
    }
};
