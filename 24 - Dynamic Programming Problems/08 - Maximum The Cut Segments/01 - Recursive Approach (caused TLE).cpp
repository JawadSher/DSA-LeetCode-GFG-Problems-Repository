class Solution
{
    public:
    // Recursive function to calculate the maximum number of cuts possible
    int solve(int n, int x, int y, int z){
        // Base case: If the length is exactly 0, no further cuts are needed
        if(n == 0) return 0;
        // Base case: If the length becomes negative, this is an invalid case
        if(n < 0) return INT_MIN;

        // Try cutting a segment of length x and recursively calculate the cuts
        int a = solve(n-x, x, y, z) + 1;
        // Try cutting a segment of length y and recursively calculate the cuts
        int b = solve(n-y, x, y, z) + 1;
        // Try cutting a segment of length z and recursively calculate the cuts
        int c = solve(n-z, x, y, z) + 1;

        // Return the maximum of the three possible cuts
        return max(a, max(b, c));
    }

    // Function to find the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Call the recursive function to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z);
        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;

        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
