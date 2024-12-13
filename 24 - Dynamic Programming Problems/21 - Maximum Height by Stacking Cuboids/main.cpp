class Solution {
public:
    // Function to solve the maximum height problem using dynamic programming
    int solve(vector<vector<int>>& cuboids, int n) {
        vector<int> dp(n);  // Array to store the maximum height of the tower ending at cuboid i
        int maxHeight = 0;  // Variable to store the overall maximum height of the tower

        // Loop through each cuboid (i represents the current cuboid being considered for the tower)
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];  // The initial height for each cuboid is its own height (third dimension)
            
            // Try to stack the current cuboid on top of all previously considered cuboids (j represents the previous cuboid)
            for (int j = 0; j < i; j++) {
                // Check if cuboid j can fit under cuboid i by comparing the dimensions
                if (cuboids[j][0] <= cuboids[i][0] &&  // width of cuboid j <= width of cuboid i
                    cuboids[j][1] <= cuboids[i][1] &&  // length of cuboid j <= length of cuboid i
                    cuboids[j][2] <= cuboids[i][2]) {  // height of cuboid j <= height of cuboid i
                    // If it fits, update the dp value for cuboid i to include the height of cuboid j
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }

            // Update the overall maximum height after considering the current cuboid
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;  // Return the maximum height that can be achieved
    }

    // Function to find the maximum height of the tower that can be made from the given cuboids
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort the dimensions of each cuboid in non-decreasing order
        for (auto& cube : cuboids) {
            sort(cube.begin(), cube.end()); // Sorting each cuboid's dimensions (height, width, length)
        }

        // Sort the cuboids by their dimensions to ensure the cuboids are arranged in the right order for the DP approach
        sort(cuboids.begin(), cuboids.end()); // Sorting cuboids lexicographically by their dimensions

        return solve(cuboids, cuboids.size());  // Call the solve function to compute the maximum height
    }
};
