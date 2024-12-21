class Solution {
public:
    // Function to find the minimum number of days to prepare food
    int minimumDays(int S, int N, int M) {
        // Total food required for S days
        int totalFood = S * M;
        
        // Check if it is impossible to prepare food
        // Case 1: If the total food required exceeds the food production capacity (7 * M > 6 * N and S > 6)
        // Case 2: If the food required per day (M) exceeds the total food production capacity per day (N)
        if ((7 * M > 6 * N && S > 6) || M > N) return -1;
        
        // If the total food is divisible by N, return the exact number of days
        if (totalFood % N == 0) return totalFood / N;
        
        // If not, return the number of days needed, rounded up (totalFood / N + 1)
        else return totalFood / N + 1;
    }
};
