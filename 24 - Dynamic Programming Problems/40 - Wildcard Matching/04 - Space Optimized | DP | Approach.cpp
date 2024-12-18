class Solution {
public:
    // Function to determine if the string matches the pattern using space-optimized dynamic programming
    int solve(string &str, string &ptrn) {
        int n = str.length(); // Length of the input string
        int m = ptrn.length(); // Length of the pattern

        // Two 1D vectors for storing the current and previous rows of the DP table
        vector<int> prev(m + 1, 0); // Represents the DP state for the previous row
        vector<int> curr(m + 1, 0); // Represents the DP state for the current row

        // Base case: An empty string matches an empty pattern
        prev[0] = true;

        // Handle cases where the string is empty but the pattern has characters
        for (int j = 1; j <= m; j++) {
            bool flag = true; // Check if all characters in the pattern up to `j` are '*'
            for (int k = 1; k <= j; k++) {
                if (ptrn[k - 1] != '*') { // If a non-'*' character is found, stop
                    flag = false;
                    break;
                }
            }

            // Set `prev[j]` to true if all characters in the pattern are '*', otherwise false
            prev[j] = flag;
        }

        // Iterate over the characters in the string
        for (int i = 1; i <= n; i++) {
            // Iterate over the characters in the pattern
            for (int j = 1; j <= m; j++) {
                // Case 1: Characters match or the pattern has '?'
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?') {
                    curr[j] = prev[j - 1]; // Match depends on the previous diagonal value
                }
                // Case 2: Pattern has '*'
                // '*' can match the current character (`prev[j]`) or match zero characters (`curr[j-1]`)
                else if (ptrn[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
                // Case 3: Characters do not match and there's no wildcard
                else {
                    curr[j] = false;
                }
            }

            // After processing the current row, update `prev` to be the same as `curr`
            prev = curr;
        }

        // The result for the full string and pattern is stored in `prev[m]`
        return prev[m];
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};
