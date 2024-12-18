class Solution {
public:
    // Recursive function to check if the pattern matches the string
    int solve(string &str, string &ptrn, int i, int j) {
        // Base case: If both string and pattern are exhausted, return true
        if (i < 0 && j < 0) return true;

        // Base case: If only the pattern is exhausted but the string is not, return false
        if (j < 0) return false;

        // Base case: If only the string is exhausted
        if (i < 0) {
            // Check if the remaining characters in the pattern are all '*'
            for (int k = 0; k <= j; k++) {
                if (ptrn[k] != '*') return false;
            }
            return true;
        }

        // Case 1: If characters match or the pattern has a '?', move both pointers
        if (str[i] == ptrn[j] || ptrn[j] == '?') {
            return solve(str, ptrn, i - 1, j - 1);
        }
        // Case 2: If the pattern has a '*', there are two possibilities:
        // - Treat '*' as matching the current character in the string (move string pointer `i` only)
        // - Treat '*' as matching zero characters (move pattern pointer `j` only)
        else if (ptrn[j] == '*') {
            return solve(str, ptrn, i - 1, j) || solve(str, ptrn, i, j - 1);
        }
        // Case 3: If characters don't match and it's not a wildcard, return false
        else {
            return false;
        }
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        // Start the recursive process from the last characters of both string and pattern
        return solve(s, p, s.length() - 1, p.length() - 1);
    }
};
