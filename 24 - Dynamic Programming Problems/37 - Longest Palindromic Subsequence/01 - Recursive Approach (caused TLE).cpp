class Solution {
public:
    // Recursive helper function to solve the problem
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    // - i: current index in the original string
    // - j: current index in the reversed string
    int solve(string str, string revStr, int i, int j) {
        // Base case: if either index goes out of bounds, return 0
        if (i >= str.length() || j >= revStr.length()) 
            return 0;
        
        // Initialize the answer variable
        int ans = 0;

        // If the characters match, add 1 to the result and move to the next indices
        if (str[i] == revStr[j]) 
            return 1 + solve(str, revStr, i + 1, j + 1);
        else {
            // If the characters do not match, find the maximum result by:
            // 1. Skipping the current character in the original string
            // 2. Skipping the current character in the reversed string
            ans = max(solve(str, revStr, i + 1, j), solve(str, revStr, i, j + 1));
        }

        // Return the computed answer
        return ans;
    }

    // Function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create a reversed version of the input string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // Start solving from the first indices of both strings
        return solve(str, revStr, 0, 0);
    }
};
